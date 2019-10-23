#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"


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





double integralPontoMedio(double (*f)(double), double a, double b, double erroMaximo) {
    double pontoMedio = (a + b)/2.0;
    double areaMaior = (b - a) * f(pontoMedio);
    double retanguloL = ((pontoMedio - a) * f(pontoMedio));
    double retanguloR = ((b - pontoMedio) * f(pontoMedio));
    double erro = areaMaior - (retanguloL + retanguloR);

    if(abs(erro) <= erroMaximo) return areaMaior;
    else return integralPontoMedio(f, a, (a + b)/2.0, erroMaximo) + integralPontoMedio(f, (b + a)/2.0, b, erroMaximo);

}