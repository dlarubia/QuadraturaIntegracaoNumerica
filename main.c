/*
Sobre o programa principal: Consiste em oferecer ao usuário um menu, descrevendo o programa e explicando o 
algoritmo. Permite, ao usário, selecionar as opções que deseja utilizar, sendo possível escolher executar um
programa sequencial ou concorrente

Autores: Daniel La Rubia e Paula Macedo

 */

#include <stdio.h>
#include <stdlib.h>
#include "quadraturaAlgorithm.c"
#include "funcoes.c"
#include "textos.c"

int main () {
	int opcao;

	exibeMenu();
	scanf("%d", &opcao);
	system("clear");
	
	while(opcao != 9) {
		system("clear");
		switch (opcao) {
			
			case 0:
			//TODO
				exibeMenu();
				scanf("%d", &opcao);
				break;
			
			case 1:
			//TODO
				textoDescricao();
				printf("\n      *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;

			case 2:
			//TODO
				textoImplementacao();
				printf("\n      *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				break;
			
			case 3:
			//TODO
				recebeParametros();

				printf("\n\nRESULTADOS DO PROGRAMA SEQUENCIAL: \n\n");
				printf("Integral de a(x) = 1 + x ==> %f\n", integralRecursiva(a, intervalo_a, intervalo_b));
				printf("Integral de b(x) = sqrt(1 - x²) ==> %f\n", integralRecursiva(b, intervalo_a, intervalo_b));
				printf("Integral de c(x) = sqrt(1 + x⁴) ==> %f\n", integralRecursiva(c, intervalo_a, intervalo_b));
				printf("Integral de d(x) = sen(x²) ==> %f\n", integralRecursiva(d, intervalo_a, intervalo_b));
				printf("Integral de e(x) = cos(e^-x) ==> %f\n", integralRecursiva(e, intervalo_a, intervalo_b));
				printf("Integral de f(x) = cos(e^-x) * x ==> %f\n", integralRecursiva(f, intervalo_a, intervalo_b));
				printf("Integral de g(x) = cos(e^-x) * (0.005 * cos(x³) + 1) ==> %f\n", integralRecursiva(g, intervalo_a, intervalo_b));
				limpaLixo();
				printf("\n      *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;
			
			case 4:
			//TODO 
				recebeNTHREADS();
				recebeParametros();

				printf("\n\nRESULTADOS CONCORRENTE: \n\n");
				printf("Integral de a(x) = 1 + x ==> %f\n", integralConcorrente(a, intervalo_a, intervalo_b));
				printf("Integral de b(x) = sqrt(1 - x²) ==> %f\n", integralConcorrente(b, intervalo_a, intervalo_b));
				printf("Integral de c(x) = sqrt(1 + x⁴) ==> %f\n", integralConcorrente(c, intervalo_a, intervalo_b));
				printf("Integral de d(x) = sen(x²) ==> %f\n", integralConcorrente(d, intervalo_a, intervalo_b));
				printf("Integral de e(x) = cos(e^-x) ==> %f\n", integralConcorrente(e, intervalo_a, intervalo_b));
				printf("Integral de f(x) = cos(e^-x) * x ==> %f\n", integralConcorrente(f, intervalo_a, intervalo_b));
				printf("Integral de g(x) = cos(e^-x) * (0.005 * cos(x³) + 1) ==> %f\n", integralConcorrente(g, intervalo_a, intervalo_b));
				limpaLixo();
				printf("\n      *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;
			
			case 5:
				recebeNTHREADS();
				recebeParametros();
				printf("\n      *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;
			
			case 6:
			//TODO
				textoInfoGrupo();
				printf("\n      *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;
			
			default:
			//TODO
				printf("Opção inválida.\n");
				printf("\n *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n\n");
				scanf("%d", &opcao);
				system("clear");
				break;
		}
	}

	return 0;
}
