#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INI 0
#define MX 100

void imprimirVetor(int *, int );
void preencherVetor(int *, int , int , int );

int main(int argc, char *argv[]){

    int *pv = NULL;

    if (argc!=2){
        printf("Use:\n\t %s <qtdElementosVetor>\n\n",argv[0]);
        exit(1);
    }

    int qtd = atoi(argv[1]);

    // pv = (int *) malloc(qtd * sizeof(int));

    // if (!pv){
    //     puts("Não há memória. Tente outra vez.\n");
    //     exit(2);
    // }

    if (! (pv = malloc(qtd * sizeof(int)) ) ) {
        puts("Não há memória. Tente outra vez.\n");
        exit(2);
    }

    preencherVetor(pv, qtd, INI, MX);
    imprimirVetor(pv, qtd);

    free(pv);

    return 0;

}

void imprimirVetor(int *pd, int qtd){
    for (int k=0; k<qtd; k++){
        printf("[%p] %d\n",pd+k,*(pd+k));
    }
}

void preencherVetor(int *pd, int qtd, int inicial, int qtdFaixa){
    srand(time(NULL));
    for (int k=0; k<qtd; k++){
        *(pd+k) = inicial + rand() % qtdFaixa;
    }
}