# QuadraturaIntegracaoNumerica
Primeiro trabalho de implementação da disciplina de Computação Concorrente, lecionada pela Prof. Silvana Rossetto em 2019-2. 

Autores: Daniel La Rubia e Paula Macedo
Data: 28/10/2019


1.Descrição do problema

O trabalho consiste em implementar o método de integração numérica retangular usando a estratégia de quadratura adaptativa para definir os subintervalos de forma dinâmica. O programa possui duas versões: sequencial e paralela, onde na versão paralela, o programa concorrente deve garantir a solução com balanceamento de carga entre as threads, objetivando um desempenho máximo.



2.Solução do problema

É criado um programa que calcula a integral definida de uma função não trivial pelo método de integração numérica do ponto médio. A   entrada do programa sequencial  é a definição do intervalo de integração e o erro máximo tolerado a ser calculado para um conjunto de funções do tipo f(x). Já no programa concorrente, além do intervalo e do erro, é solicitado também o número de threads do programa. 

Foram implementados três algoritmos: Sequencial, Concorrente Balanceado e Concorrente Desbalanceado. O algoritmo sequencial foi implementado utilizando a recursividade e o algoritmo concorrente desbalanceado fez uso da mesma função recursiva, sendo a única diferença a subdivisão do intervalo [a, b] em N, que é o número de threads. O algoritmo gera uma árvore de recursividade e realiza o somatório dos valores que são aceitos de acordo com o erro passado pelo usuário. 

Já no algoritmo de integração concorrente balanceado, foi utilizada uma pilha, onde as threads estariam funcionando como produtoras/consumidoras, consumindo o conjunto de dados armazenado no topo da pilha e realizando uma operação para verificar se o erro da área está no limite tolerado. Se não estiver, é realizado um push com os dois novos retângulos. A  fim de balancear o problema, é realizada uma carga inicial da pilha com N valores (número de threads).

Link para relatório na íntegra => https://docs.google.com/document/d/1a6lZX86-5Dj_pvYj_HjI8cOn4ny5BodpZish_KbDddw/edit?usp=sharing

3. Como compilar

<p>
O programa deve ser compilado da seguinte maneira: main.c -o main -lm - lpthread.</p>
<p>
./main</p>
Após os comandos, aparecerá um menu e o usuário irá escolher as opções de execução, para por fim escolher os intervalos, erros e número de threads.






