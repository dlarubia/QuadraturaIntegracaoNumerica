# QuadraturaIntegracaoNumerica
Primeiro trabalho de implementação da disciplina de Computação Concorrente, lecionada pela Prof. Silvana Rossetto em 2019-2. 
Autores:
Data:


1.Descrição do problema

  O trabalho consiste em implementar o método de integração numérica retangular usando a estratégia de quadratura adaptiva para
  definir o subintervalos de forma dinâmica. O programa possui duas versões: sequencial e paralela, onde na versão concorrente 
  deve-se garantir a solução com balancemento de carga entre as threads, objetivando um desempenho máximo.

2.Solução do problema 

3.Avaliação de desempenho: Sequencial x Paralelo

4.Testes realizados

  Dado um determinado conjunto de testes, é feita a comparação entre os tempos de execução da solução sequencial e da solução paralela. 

5.Modularidade do programa 

  A fim de permitir uma maior clareza ao programa, o mesmo foi modularizado da seguinte forma: main.c, implementacao.c, protótipo.h e
  estruturas.h.
  Na main.c encontramos a função main que faz a chamada ao métodos e funções implementadas pelo ARQUIVO A. ...
  No prototipo.h, encontramos todos os protótipos de funções que serão implementadas em implementacao.c. E em estuturas.h encontra-se     todas as estruturas de dados criadas para atender a necessidade deste programa.

6.Interface usuário 


7.Dificuldades encontradas 

  - Entender como funciona a resolução matemática do problema apresentado e saber aplicar o método.

8.Possíveis melhorias

  O programa encontra-se funcional, mas pode-se acrescentar outros features ao mesmo, como : plotagem de gráficos, 
  elaboração de menu simplificado, permitindo ao usuário com algum tipo dificuldade de passar paramêtros pela
  linha de comando uma fácil manipulação da ferramenta. 


Conclusão

