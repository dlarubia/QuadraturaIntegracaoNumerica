void textoDescricao() {
    printf("COMPREENDA O PROBLEMA\n\nO trabalho consiste em implementar o método de integração numérica retangular usando a estratégia de quadratura adaptiva para definir o subintervalos de forma dinâmica. O programa possui duas versões: sequencial e paralela, onde na versão concorrente deve-se garantir a solução com balancemento de carga entre as threads, objetivando um desempenho máximo.\n");
}


void textoImplementacao() {
    printf("SOBRE A IMPLEMENTAÇÃO\n\nO problema foi implementado utilizando a recursividade no algoritmo de integração sequencial e a pilha no algoritmo de integração concorrente. Quanto as diferenças nas implementações, o primeiro caso gera simplesmente uma árvore de recursividade e realiza o somatório dos valores que são aceitos de acordo com o erro passado pelo usuário. No segundo caso, do programa concorrente, o problema é inicialmente dividido no número de threads desejadas pelo usuário (a fim de balancear o problema). Os N (número de threads) subintervalos são empilhados e as threads iniciam o processamento. Quando a pilha estiver vazia e não houverem mais dados a serem processados, o algoritmo é encerrado.\n");
}


void textoInfoGrupo() {
    printf("Trabalho 1 - Problema da Quadratura de Integração Numérica\nProfessora Silvana Rossetto\nPeríodo 2019/2\nAutores:\n * Daniel La Rubia -- DRE: 115033904\n * Paula Macedo -- DRE: XXXXXXXXX\n");
}


void exibeMenu() {
    printf(" |--------------------------------------------------------------------|\n \
|                Problema da Quadratura numérica                     |\n \
|                                                                    |\n \
| Selecione a opção desejada:                                        |\n \
|     1 - Compreenda o problema                                      |\n \
|     2 - Sobre a implementação                                      |\n \
|     3 - Execução do Programa implementado de forma Sequencial      |\n \
|     4 - Execução do Programa implementado de forma Concorrente     |\n \
|     5   Comparar programa sequencial e concorrente                 |\n \
|     6 - Membros do grupo                                           |\n \
|--------------------------------------------------------------------|\n");
}