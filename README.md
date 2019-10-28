# QuadraturaIntegracaoNumerica
Primeiro trabalho de implementação da disciplina de Computação Concorrente, lecionada pela Prof. Silvana Rossetto em 2019-2. 
Autores:
Data:


1.Descrição do problema

O trabalho consiste em implementar o método de integração numérica retangular usando a estratégia de quadratura adaptativa para definir o subintervalos de forma dinâmica. O programa possui duas versões: sequencial e paralela, onde na versão paralela, o programa concorrente deve garantir a solução com balanceamento de carga entre as threads, objetivando um desempenho máximo.


2.Solução do problema

É criado um programa que calcula a integral definida de uma função não trivial pelo método de integração numérica do ponto médio. A   entrada do programa sequencial  é a definição do intervalo de integração e o erro máximo tolerado a ser calculado para um conjunto de funções do tipo f(x). Já no programa concorrente, além do intervalo e do erro, é solicitado também o número de threads do programa. 

O problema foi implementado utilizando a recursividade no algoritmo de integração sequencial e a pilha no algoritmo de integração concorrente. Quanto às diferenças nas implementações, o primeiro caso gera simplesmente uma árvore de recursividade e realiza o somatório dos valores que são aceitos de acordo com o erro passado pelo usuário. No segundo caso, do programa concorrente, o problema é inicialmente dividido no número de threads desejadas pelo usuário (a fim de balancear o problema). Os N (número de threads) subintervalos são empilhados e as threads iniciam o processamento. Quando a pilha estiver vazia e não houverem mais dados a serem processados, o algoritmo é encerrado.


3.Testes realizados

O ambiente de testes utilizados neste trabalho é baseado em Linux e a versão do compilador gcc utilizado foi a 7.4.0.

O programa foi compilado da seguinte maneira: main.c -o main -lm - lpthread.

Dado um determinado conjunto de testes, é feita a comparação entre os tempos de
execução da solução sequencial e da solução paralela.
  
As funções utilizadas neste trabalho encontram-se abaixo: 
  
 a) f(x) = 1+x
 b) f(x) = sqrt(1-x^2), de -1 < x < 1
 c) f(x) = sqrt(1-x^4)
 d) f(x) = sin(x^2)
 e) f(x) = cos(exp[-x])
 f) f(x) = cos(exp[-x]) * x
  g) f(x) = cos(exp[-x]) * (0.005 * x^3 + 1)

Os intervalos utilizados, erros máximo tolerados e no caso do programa paralelo, o número de threads são explicitados na tabela a seguir, assim como o tempo de execução de cada teste.


 
4.Avaliação de desempenho: Sequencial x Paralelo
  
Observando-se o resultado obtido para os testes apresentados anteriormente, fica evidenciado que o resultado obtido no cálculo da integral tanto na versão sequencial quanto da versão paralela é o mesmo. 

  
5.Modularidade do programa

O programa encontra-se modularizado com a finalidade de garantir ao programa legibilidade e permitir a facilidade em sua manutenção. 

O programa foi subdividido em arquivos de extensão .c e .h. Existe um arquivo para tratar exclusivamente do gerenciamento das threads (criação, sincronização, alocação de memória e encerramento). Existe um arquivo com  a implementação das funções calculadas pelo programa. Há outro arquivo que trata da questão do timer, para medir o tempo de execução do programa para cada caso. Há o arquivo que trata de fato da implementação do método, neste arquivo encontram-se as funções tanto para a solução sequencial, quanto a versão concorrente. E há três arquivos do tipo main: mainsequencial.c, mainconcorrente.c e mainextra.c (versão com menu, que integra programa concorrente e sequencial).


6.Interface usuário (Versão extra)

A fim de facilitar a visualização da solução do problema e unificar a chamada para os programas sequenciais e concorrente, uma versão extra do trabalho com menu foi criada . Este menu, oferece as opções necessárias para que um usuário do programa entenda a problemática, qual abordagem implementada para solução da mesma, além da execução dos programas em separado e execução em conjunto como forma de comparativo.

Adicionalmente, é possível encontrar as informações da dupla, como nome e DRE.

Ao escolher as opções 1 ou 2, será retornado ao usuário uma descrição do tópico selecionado.

Ao escolher 3, será solicitado ao usuário que digite primeiramente o intervalo [a,b], sendo a [enter], b [enter] e o erro [enter]. Ao escolher 4 ou 5, será solicitado o número de threads [enter] e logo após o mesmo que a opção 3.

Os resultados são impressos com suas respectivas funções, além do tempo de execução para cada função e o tempo de execução total do programa.

Ao final de todas as opções, o usuário tem a opção de retornar ao menu principal ou encerrar o programa.


7.Dificuldades encontradas 

Durante a elaboração da resolução deste trabalho encontramos certas dificuldades que serão pontuadas e explicitadas abaixo:
  
Entender como funciona a resolução matemática do problema apresentado e saber aplicar o método.
Após o entendimento do funcionamento do método, dificuldade em transformar a solução em recursiva e a realização do cálculo do erro do método que deve ser comparado ao erro máximo pela linha de comando. 
Primeiramente tentamos a abordagem de calcular de forma macetada a integral definida das funções e em seguida subtrair o resultado obtido pelo método para por fim achar o erro. Tal abordagem foi falha, pois a mesma é de fácil implementação para os primeiros casos do conjunto de testes, após isso, o código se torna muito extenso, faz uso de outras funções como cossecante, cotangente e entre outros, além de fugir da proposta do trabalho que utiliza o método pelo fato da integral nestes casos não ser trivial.
Terminada a versão sequencial, implementar a versão paralela. A dificuldade maior foi pensar em que abordagem utilizar, já que apenas dividir o trabalho de cálculo das funções entre as threads, isto é, por uma thread para calcular apenas n funções e a outra calcula mais n funções e assim por diante, é uma estratégia que não gera um balanceamento de carga.



8.Conclusão




