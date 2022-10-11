#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int *, int, int, int);
void imprimirMatriz(int *, int, int);
void imprimirVetor(int *, int );

int main(){

    int *pData = NULL;
    int nl, nc;

    puts("Digite a quantidade de linhas:");
    scanf("%d",&nl);

    puts("Digite a quantidade de colunas:");
    scanf("%d",&nc);

    pData = malloc(nl * nc * sizeof(int));

    if (!pData){
        puts("Erro. Tente quantidade de linhas e colunas diferentes.");
        exit(1);
    }

    preencherVetor(pData, nl*nc, 0, 100);
    puts("--------");
    imprimirVetor(pData, nl * nc);
    puts("--------");
    imprimirMatriz(pData, nl, nc);

    return 0;

}



void preencherVetor(int *pd, int qtd, int inicial, int qtdFaixa){
    srand(time(NULL));
    for (int k=0; k<qtd; k++){
        *(pd+k) = inicial + rand() % qtdFaixa;
    }
}

void imprimirMatriz(int *pd, int qnl, int qnc){

    for (int k=0; k<qnl; k++){
        for (int j=0; j< qnc; j++){
            printf("%3d ",*(pd + qnc * k + j));
        }
        printf("\n");
    }

}

void imprimirVetor(int *pd, int qtd){
    for (int k=0; k<qtd; k++){
        printf("[%p] %d\n",pd+k,*(pd+k));
    }
}