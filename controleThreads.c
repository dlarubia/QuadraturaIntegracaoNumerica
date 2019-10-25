#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


pthread_t *tid_sistema;
int nthreads = 0, t, *tid;


void recebeNTHREADS() {
    do {
        printf("Digite o número de threads que deseja utilizar (1 a 8): ");
        scanf("%d", &nthreads);
    }
    while( nthreads <= 0 || nthreads > 8);
}


void cria_threads(void *f) {
    tid_sistema = (pthread_t *) malloc(sizeof(pthread_t) * nthreads);
    if(tid_sistema == NULL) {
        printf("--ERRO: malloc('aloca espaço para vetor de identificadores das threads')\n");
        exit(-1);
    }

    for(t = 0; t < nthreads; t++) {
        tid = malloc(sizeof(int));
        if(tid == NULL) {
            printf("--ERRO: malloc('criação das threads')\n");
            exit(-1);
        }

        *tid = t;
        if(pthread_create(&tid_sistema[t], NULL, f, (void*) tid)) {
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }
    }
}


void aguarda_encerramento_threads() {
    for(t = 0; t < nthreads; t++) {
        if(pthread_join(tid_sistema[t], NULL)) {
            printf("--ERRO: pthread_join()\n");
            exit(-1);
        }
    }
}