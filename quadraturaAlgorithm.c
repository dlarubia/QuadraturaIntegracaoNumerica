/**
 * Arquivo que conterá a implementação completa do método de integração por ponto médio, utilizando
 * quadratura adaptativa. 
 * 
 * Descrição do algoritmo:
 * Input => Função F (função contínua no intervalo), Intervalo [a,b],
 * número de iterações (que será substituído posteriormente pelo erro máximo)
 * 
 * Passos:
 * 1- Calcular passo = (b - a)/n => Será usado como tamanho do passo a cada iteração
 * 2- Definir 0 na variável integral
 * 3- Inicializar uma variável i como 1
 * 4- Somar passo * f(a + (i - 1) * passo) à variável integral
 * 5- Incrementar i em 1 unidade
 * 6- Checar se i é menor ou igual a n. Se for, ir para o passo 4
 * 7- Encerrar o algoritmo e retornar a integral
 * 
 * --------
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "controleThreads.c"

#define N 1024

typedef struct Dados {
    double a;
    double b;
    double (*f)(double);
} Dados;

Dados Buffer[N];
double intervalo_a, intervalo_b, erroMaximo, valorIntegral = 0;
int topo = -1;
pthread_mutex_t mutex, mutex1;


Dados inicializaRetangulo(double a, double b, double (*f)(double)) {
    Dados retangulo;
    retangulo.a = a;
    retangulo.b = b;
    retangulo.f = f;

    return retangulo;
}


double calculaAreaRetangulo(double a, double b, double (*f)(double)) {
    return (b - a) * f((a + b) / 2.0);
}


double integralRecursiva(double (*f)(double), double a, double b) {
    double areaMaior = calculaAreaRetangulo(a, b, f);
    double areaEsquerda = calculaAreaRetangulo(a, (a+b)/2.0, f);
    double areaDireita = calculaAreaRetangulo((a+b)/2.0, b, f);

    if(fabs(areaMaior - areaEsquerda - areaDireita) > erroMaximo) {
        return integralRecursiva(f, a, (a+b)/2) + integralRecursiva(f, (a+b)/2, b);
    }

    return areaMaior;
}


void push(int n) {
    topo += n;
}


void pop(int n) {
    topo -= n;
}


void preenchePilhaInicial(int nthreads, double a, double b, double (*f)(double)) {
    double espacamento = (b - a) / nthreads;

    for (int i = 0; i < nthreads; i++) {
        Buffer[i] = inicializaRetangulo(a + i * espacamento, (a + i * espacamento) + espacamento, f);
        push(1);
    }
    /* //Caso deseje verificar a que tanto o algoritmo sequencial quanto o concorrente geram o mesmo resultado, é necessário que se troque a inicialização da pilha
    Buffer[0] = inicializaRetangulo(a, b, f);
    push(1);
    */
}


void calculaRetangulos(Dados retangulo) {
    pop(1);
    pthread_mutex_unlock(&mutex);

    double a = retangulo.a, b = retangulo.b;
    double pontoMedio = (a + b)/2.0;
    double areaMaior = calculaAreaRetangulo(a, b, retangulo.f);
    double areaRetanguloEsquerda = calculaAreaRetangulo(a, pontoMedio, retangulo.f);
    double areaRetanguloDireita = calculaAreaRetangulo(pontoMedio, b, retangulo.f);
    double erro = areaMaior - (areaRetanguloEsquerda + areaRetanguloDireita);

    if(fabs(erro) > erroMaximo) {
        pthread_mutex_lock(&mutex);
        Buffer[topo + 1] = inicializaRetangulo(retangulo.a, pontoMedio, retangulo.f);
        Buffer[topo + 2] = inicializaRetangulo(pontoMedio, retangulo.b, retangulo.f);
        push(2);
        pthread_mutex_unlock(&mutex);
    }
    else {
        pthread_mutex_lock(&mutex1);
        valorIntegral += areaMaior;
        pthread_mutex_unlock(&mutex1);
    }

    pthread_mutex_lock(&mutex);
}


void *Integrar (void *tid) {
    int id = *(int*) tid;
    int contador = 0;
    pthread_mutex_lock(&mutex);
    while(topo != -1) {
        calculaRetangulos(Buffer[topo]);
        contador++;
    }
    pthread_mutex_unlock(&mutex);
    free(tid);
    pthread_exit(NULL);
}


double integralConcorrente(double (*f)(double), double a, double b) {
    valorIntegral = 0;
	preenchePilhaInicial(nthreads, a, b, f);
	cria_threads(Integrar);
	aguarda_encerramento_threads();
	return valorIntegral;
}


void recebeParametros() {
    printf("Insira o valor inicial (a), sabendo que o intervalo vai de a -> b: ");
	scanf("%lf", &intervalo_a);
	printf("Insira o valor final (b): ");
	scanf("%lf", &intervalo_b);
	printf("Digite o valor de erro tolerado: ");
	scanf("%lf", &erroMaximo);
}


void limpaLixo() {
    intervalo_a = 0;
    intervalo_b = 0;
    erroMaximo = 0;
    valorIntegral = 0;
}