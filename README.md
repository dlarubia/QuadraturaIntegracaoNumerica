# QuadraturaIntegracaoNumerica
Primeiro trabalho de implementação da disciplina de Computação Concorrente, lecionada pela Prof. Silvana Rossetto em 2019-2. 
Autores: Daniel La Rubia e Paula Macedo
Data:


1.Descrição do problema

  O trabalho consiste em implementar o método de integração numérica retangular usando a estratégia de quadratura adaptativa para
  definir o subintervalos de forma dinâmica. O programa possui duas versões: sequencial e paralela, onde na versão concorrente 
  deve-se garantir a solução com balanceamento de carga entre as threads, objetivando um desempenho máximo.

2.Solução do problema

  É criado um programa que calcula a integral definida de uma função não trivial pelo método de integração numérica do ponto médio. A   entrada é um conjunto de funções do tipo f(x) definidas no intervalo [a, b]. O programa de forma recursiva subdivide o intervalo passado na entrada do programa em subintervalos, no formato de retângulos.  e faz o somatório do cálculo da integral de cada subintervalo resultando na integral total para o intervalo [a,b]. O programa checa se o erro do resultado obtido por esta abordagem está dentro do limite máximo do erro tolerado passado pela entrada. Caso não esteja, ele subdivide novamente o intervalo em mais subintervalos, retângulos e chama a função novamente. A condição de parada é o erro da função ser inferior ao erro máximo tolerado passado na entrada do programa.

3.Avaliação de desempenho: Sequencial x Paralelo

4.Testes realizados //NÃO IMPLEMENTADO 

  Dado um determinado conjunto de testes, é feita a comparação entre os tempos de execução da solução sequencial e da solução paralela.
  
  As funções utilizadas para testes neste trabalho encontram-se abaixo: 
  
 * a) f(x) = 1+x
 * b) f(x) = sqrt(1-x^2), de -1 < x < 1
 * c) f(x) = sqrt(1-x^4)
 * d) f(x) = sin(x^2)
 * e) f(x) = cos(exp[-x])
 * f) f(x) = cos(exp[-x]) * x
 * g) f(x) = cos(exp[-x]) * (0.005 * x^3 + 1)

  O programa na versão sequencial (mainseq.c) foi compilado da seguinte forma: gcc mainseq.c -o programa -lm . 
  
  Os testes para versão sequencial tiveram os respectivos valores para o intervalo [a,b] e o erro máximo.
  
  
  
  
5.Modularidade do programa //NÃO IMPLEMENTADO

  A fim de permitir uma maior clareza ao programa, o mesmo foi modularizado da seguinte forma: main.c, implementacao.c, protótipo.h e
  estruturas.h.
  Na main.c encontramos a função main que faz a chamada ao métodos e funções implementadas pelo ARQUIVO A. ...
  No prototipo.h, encontramos todos os protótipos de funções que serão implementadas em implementacao.c. E em estuturas.h encontra-se     todas as estruturas de dados criadas para atender a necessidade deste programa.

6.Interface usuário 


7.Dificuldades encontradas 

  Durante a elaboração da resolução deste trabalho encontramos certas dificuldades que serão pontuadas e explicitadas abaixo:
  
  - Entender como funciona a resolução matemática do problema apresentado e saber aplicar o método.
  - Após o entendimento do funcionamento do método, dificuldade em transformar a solução em recursiva e a realização do cálculo do erro do método que deve ser comparado ao erro máximo pela linha de comando. 
  - Primeiramente tentamos a abordagem de calcular de forma macetada a integral definida das funções e em seguida subtrair o resultado obtido pelo método. Tal abordagem foi falha, pois a mesma é de fácil implementação para os primeiros casos do conjunto de testes, após isso, o código se torna muito extenso, faz uso de outras funções como cossecante, cotangente e entre outros, além de fugir da proposta do trabalho que utiliza o método pelo fato da integral nestes casos não ser trivial.

8.Possíveis melhorias

  O programa encontra-se funcional, mas pode-se acrescentar outros features ao mesmo, como : plotagem de gráficos, 
  elaboração de menu simplificado, permitindo ao usuário com algum tipo dificuldade de passar paramêtros pela
  linha de comando uma fácil manipulação da ferramenta. 


Conclusão

    

