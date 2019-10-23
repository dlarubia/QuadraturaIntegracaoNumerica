/*** Trabalho 1 - Versão Principal programa sequencial
Autores: Daniel La Rubia e Paula Macedo
Data: 15/10/2019
Descrição: Implementação da versão sequencial do programa que utiliza o método de integração numérica retangular(ponto médio).
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.c"

int main (int argc, char** argv){

// Variável para armazenar tempo
	clock_t tempo;
// O usuário deverá informar na linha de comando o intervalo [a,b] e o erro máximo e
	if(argc!=4) {
		puts("Entre com intervalo [a, b] e o erro na seguinte formatação : ./nome_programa a b e");
		return 1;
	}
// Variáveis do programa
	float intervaloA = atof(argv[1]);
	float intervaloB = atof(argv[2]);
	float erroMax = atof(argv[3]);
	
	tempo = clock();
	printf("VALOR INTEGRAL a(x): %lf\n", integralPontoMedio(a, intervaloA, intervaloB, erroMax));
	printf("VALOR INTEGRAL b(x): %lf\n", integralPontoMedio(b, intervaloA, intervaloB, erroMax));
	printf("VALOR INTEGRAL c(x): %lf\n", integralPontoMedio(c, intervaloA, intervaloB, erroMax));
	printf("VALOR INTEGRAL d(x): %lf\n", integralPontoMedio(d, intervaloA, intervaloB, erroMax));
	printf("VALOR INTEGRAL e(x): %lf\n", integralPontoMedio(e, intervaloA, intervaloB, erroMax));
	printf("VALOR INTEGRAL f(x): %lf\n", integralPontoMedio(f, intervaloA, intervaloB, erroMax));
	printf("VALOR INTEGRAL g(x): %lf\n", integralPontoMedio(g, intervaloA, intervaloB, erroMax));
	t = clock() - t;
	printf("Tempo de execução: %lf", ((double)tempo)/((CLOCKS_PER_SEC/1000)))
	return 0;

}





				
