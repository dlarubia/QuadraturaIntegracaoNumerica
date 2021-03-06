/**
 * Trabalho 1 - Computação Concorrente
 * Professora Silvana Rossetto
 * Período 2019.2
 * Autores: Daniel La Rubia e Paula Macedo
 * 
 * Descrição do arquivo: Contém a implementação dos algoritmos de integração por ponto médio, utilizando quadratura adaptativa,
 * bem como as funções auxiliares necessárias
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "controleThreads.c"

#define N 102400

typedef struct Dados {
    double a;
    double b;
    double (*f)(double);
} Dados;

Dados Buffer[N];
double intervalo_a, intervalo_b, erroMaximo, valorIntegral = 0;
int topo = -1;
pthread_mutex_t mutex, mutex1, mutex2;


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
    double erro = areaMaior - (areaDireita + areaEsquerda);

    if(fabs(erro) > erroMaximo) {
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
    pthread_mutex_lock(&mutex);
    while(topo != -1) {
        calculaRetangulos(Buffer[topo]);
    }
    pthread_mutex_unlock(&mutex);
    free(tid);
    pthread_exit(NULL);
}


void *IntegrarDesbalanceada (void *tid) {
    int id = *(int*) tid;
    double resultadoIntegral = integralRecursiva(Buffer[id].f, Buffer[id].a, Buffer[id].b);
    pthread_mutex_lock(&mutex2);
    valorIntegral += resultadoIntegral;
    pthread_mutex_unlock(&mutex2);
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


double integralConcorrenteDesbalanceadaRecursiva(double (*f)(double), double a, double b) {
    valorIntegral = 0;
    preenchePilhaInicial(nthreads, a, b, f);
    cria_threads(IntegrarDesbalanceada);
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