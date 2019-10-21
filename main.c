/*** Trabalho 1 - Versão Principal programa sequencial
Autores: 
Data: 15/10/2019
Descrição: Implementação da versão sequencial do programa que utiliza o método de integração numérica retangular(ponto médio).
 ***/
#include <stdio.h>
#include <stdlib.h>


int main (int c, char** argv){

// O usuário deverá informar na linha de comando o intervalo [a,b] e o erro máximo e
	if(argc!=4) {
		puts("Entre com intervalo [a, b] e o erro na seguinte formatação : ./nome_programa a b e");
		return 1;
	}
// Variáveis do programa
	float intervaloA = atof(argv[1]);
	float intervaloB = atof(argv[2]);
	float erroMax = atof(argv[3]);
	
	return 0;
}
