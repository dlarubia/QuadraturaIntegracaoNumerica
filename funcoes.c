/*
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
#include <math.h>

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