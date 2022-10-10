#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15
#define MX 100 // Quant. de elementos na faixa de valores do vetor
#define INI 0

void getMenor(int *pd, int qtd, int *pMenor);
void getMaior(int *pd, int qtd, int *pMaior);
void imprimirVetor(int *pd, int qtd);

int main(){
    int v[TAM], maior, menor;
    int *pv = NULL; // int *pv = v;

    srand(time(NULL));

    pv = v; //pv = &v[0];
    for (int k=0; k<TAM; k++){
        // *(pv+k) = INI + rand() % MX; 
        *(v+k) = INI + rand() % MX;
    }
    imprimirVetor(v, TAM);

    printf("---\n");
    getMenor(v, TAM, &menor);
    getMaior(v, TAM, &maior);

    printf("Menor: %d\nMaior: %d\n",maior, menor);

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
        printf("%d ",*(pd+k));
    }
    printf("\n");
}