/*
Sobre o programa principal: Consiste em oferecer ao usuário um menu, descrevendo o programa e explicando o 
algoritmo. Permite, ao usário, selecionar as opções que deseja utilizar, sendo possível escolher executar um
programa sequencial ou concorrente

Autores: Daniel La Rubia e Paula Macedo

 */

#include <stdio.h>
#include <stdlib.h>

int main () {
	int opcao;
	
	printf("Problema da Quadratura numérica\n\n \
			Selecione a opção desejada:\n \
			1 - Compreenda o problema\n \
			2 - Sobre a implementação\n \
			3 - Execução do Programa implementado de forma Sequencial\n \
			4 - Execução do Programa implementado de forma Concorrente\n \
			5 - Descrição do Trabalho\n");
	scanf("%d", &opcao);
	
	do {
		switch (opcao) {
			
			case 0:
			//TODO
				printf("MENU PRINCIPAL \n 1\n 2\n 3\n 4\n 5\n");
				scanf("%d", &opcao);
				break;
			
			case 1:
			//TODO
				printf("Descrição\n");
				printf("Digite 0 para retornar ao menu ou 9 para encerrar a aplicação.\n");
				scanf("%d", &opcao);
				break;

			case 2:
			//TODO
				printf("Descrição\n");
				printf("Digite 0 para retornar ao menu ou 9 para encerrar a aplicação.\n");
				scanf("%d", &opcao);
				break;
			
			case 3:
			//TODO
				printf("Descrição\n");
				printf("Digite 0 para retornar ao menu ou 9 para encerrar a aplicação.\n");
				scanf("%d", &opcao);
				break;
			
			case 4:
			//TODO 
				printf("Descrição\n");
				printf("Digite 0 para retornar ao menu ou 9 para encerrar a aplicação.\n");
				scanf("%d", &opcao);
				break;
			
			case 5:
			//TODO
				printf("Descrição\n");
				printf("Digite 0 para retornar ao menu ou 9 para encerrar a aplicação.\n");
				scanf("%d", &opcao);
				break;
			
			case 9:
			//TODO
				break;
			
			default:
			//TODO
				printf("Opção inválida.\n");
				printf("Digite 0 para retornar ao menu ou 9 para encerrar a aplicação.\n");
				scanf("%d", &opcao);
				break;
		}
	} while (opcao != 9);



	return 0;
}
