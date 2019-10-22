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
 * Funções que devem ser calculadas:
 * a(x) = 1 + x
 * b(x) = sqrt(1 - x²), -1 < x < 1
 * c(x) = sqrt(1 + x⁴)
 * d(x) = sen(x²)
 * f(x) = cos(e^-x)
 * g(x) = cos(e^-x) * x
 * h(x) = cos(e^-x) * (0.005 * x³ + 1)
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define euler M_PI

double a(double x) {
    return 1 + x;
}

double b(double x) {
    return sqrt(1 - pow(x,2));
}

double c(double x) {
    return sqrt(1 + pow(x, 4));
}

double d(double x) {
    return sin(pow(x,2));
}

double e(double x) {
    return cos(pow(euler, -x));
}

double f(double x) {
    return cos(pow(euler, -x)) * x;
}

double g(double x) {
    return cos(pow(euler, -x)) * (0.005 * pow(x,3) + 1);
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

