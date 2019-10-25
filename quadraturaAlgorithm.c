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

#define N 1024

typedef struct Dados {
    double a;
    double b;
    double (*f)(double);
} Dados;

Dados Buffer[N];
double erroMaximo, valorIntegral = 0;
int posicao = -1;
pthread_mutex_t mutex, mutex1;

Dados inicializaRetangulo(double a, double b, double (*f)(double)) {
    Dados retangulo;
    retangulo.a = a;
    retangulo.b = b;
    retangulo.f = f;

    return retangulo;
}

//TODO: Próximo passo é deixar de receber o parametro iteracoes e passar a controlar o término da função através do erro. Eliminar o for e tornar recursivo
double integralPontoMedio(double (*f)(double), double a, double b, int iteracoes) {
    double passo = (b - a) / iteracoes;
    double integral = 0;
    for(int i = 1; i <= iteracoes; i++) {
        integral += passo * f(a + (i - 1) * passo);
    }

    return integral;
}

// Método do Leo
double integralPontoMedio2(double (*f)(double), double a, double b, int iteracoes) {
    double passo = (b - a) / iteracoes;
    double integral = 0;
    for(double i = a; i <= (b - passo); i+= passo) {
        integral += f(i + passo/2.0);
    }

    return passo * integral;
}

double integralPontoMedioRecursivo(double (*f)(double), double a, double b, double erroMaximo) {
    double pontoMedio = (a + b)/2.0;
    double areaMaior = (b - a) * f(pontoMedio);
    double retanguloL = ((pontoMedio - a) * f(pontoMedio));
    double retanguloR = ((b - pontoMedio) * f(pontoMedio));
    double erro = areaMaior - (retanguloL + retanguloR);

    if(abs(erro) <= erroMaximo) return areaMaior;
    else return integralPontoMedio(f, a, (a + b)/2.0, erroMaximo) + integralPontoMedio(f, (b + a)/2.0, b, erroMaximo);
}


void defineErroMaximo(double erro) {
    erroMaximo = erro;
}

//TODO: Avaliar a necessidade do MUTEX
void push(int n) {
    posicao++;
}

//TODO: Avaliar a necessidade do MUTEX
void pop(int n) {
    posicao--;
}

void preenchePilhaInicial(int nthreads, double a, double b, double (*f)(double)) {
    printf("Vou preencher a pilha\n");
    double espacamento = (b - a) / nthreads;

    for (int i = 0; i < nthreads; i++) {
        printf("Preenchendo a pilha %d!!\n", i);
        Buffer[i] = inicializaRetangulo(a + i * espacamento, (a + i * espacamento) + espacamento, f);
        push(1);
    }
}


//TODO: Verificar a corretude do PUSH e POP na pilha, bem como o controle de sincronização
void calculaRetangulos(Dados retangulo) {
    pop(1);
    double pontoMedio = (retangulo.a + retangulo.b)/2.0;
    double areaMaior = (retangulo.b - retangulo.a) * retangulo.f(pontoMedio);
    double areaRetanguloEsquerda = ((pontoMedio - retangulo.a) * retangulo.f(pontoMedio));
    double areaRetanguloDireita = ((retangulo.b - pontoMedio) * retangulo.f(pontoMedio));
    double erro = areaMaior - (areaRetanguloEsquerda + areaRetanguloDireita);

    printf("PontoMedio = %f\n", pontoMedio);
    printf("areaMaior = %f\n", areaMaior);
    printf("areaRetanguloEsquerda = %f\n", areaRetanguloEsquerda);
    printf("areaRetanguloDireita = %f\n", areaRetanguloDireita);
    printf("erro = %f\n", erro);

    pthread_mutex_unlock(&mutex);

    if(abs(erro) > erroMaximo) {
        pthread_mutex_lock(&mutex);
        printf("Posicao = %d\n", posicao);
        Buffer[posicao + 1] = inicializaRetangulo(retangulo.a, pontoMedio, retangulo.f);
        printf("Posicao + 1 = %d", posicao + 1);
        Buffer[posicao + 2] = inicializaRetangulo(pontoMedio, retangulo.b, retangulo.f);
        printf("Posicao + 1 = %d", posicao + 2);
        push(2);
        pthread_mutex_unlock(&mutex);
    }
    else {
        printf("Eu cheguei no else\n");
        pthread_mutex_lock(&mutex1);
        valorIntegral += areaMaior;
        pthread_mutex_unlock(&mutex1);
    }

    pthread_mutex_lock(&mutex);
}


void *Integrar (void *tid) {
    int id = *(int*) tid;
    printf("Eu to rodando!!! \n");
    printf("posicao = %d\n", posicao);
    printf("tid: %d\n", id);
    pthread_mutex_lock(&mutex);
    while(posicao != -1) {
        printf("tid: %d\n", id);
        //TODO: Verificar a corretude do controle de exclusão mútua  
        calculaRetangulos(Buffer[posicao]);
    }
    pthread_mutex_unlock(&mutex);
    printf("A THREAD NÚMERO %d ACABOU COM CERTEZA!!!!\n", id);
    posicao = -1;
    free(tid);
    pthread_exit(NULL);
}