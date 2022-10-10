#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15
#define MX 100 // Quant. de elementos na faixa de valores do vetor
#define INI 0

void getMenor(int *, int, int *);
void getMaior(int *, int, int *);
void imprimirVetor(int *, int);
void preencherVetor(int *, int, int, int);
int *getEndMenor(int *, int);
int *getEndMaior(int *, int);

int main(){
    int v[TAM], maior, menor;
    
    

    preencherVetor(v, TAM, INI, MX);
    
    imprimirVetor(v, TAM);

    printf("---\n");
    getMenor(v, TAM, &menor);
    getMaior(v, TAM, &maior);

    printf("[%p] Menor: %d\n[%p] Maior: %d\n",getEndMenor(v,TAM), menor, getEndMaior(v,TAM), maior);

    return 0;

}

void getMenor(int *pd, int qtd, int *pMenor){
    *pMenor = *pd;
    for (int k=1; k<qtd; k++){
        *pMenor = ( *(pd+k) < *pMenor )?*(pd+k):*pMenor;
    }
}

void getMaior(int *pd, int qtd, int *pMaior){
    *pMaior = *pd;
    for (int k=1; k<qtd; k++){
        *pMaior = (*(pd+k) > *pMaior)?*(pd+k):*pMaior; 
    }
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

int *getEndMenor(int *pd, int qtd){
    int *pm = NULL;
    pm = pd;
    for (int k=1; k<qtd; k++){
        pm = ( *(pd+k) < *pm )?(pd+k):pm;
    }
    return pm;
}

int *getEndMaior(int *pd, int qtd){
    int *pm = NULL;
    pm = pd;
    for (int k=1; k<qtd; k++){
        pm = ( *(pd+k) > *pm )?(pd+k):pm;
    }
    return pm;
}