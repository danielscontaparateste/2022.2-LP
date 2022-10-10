#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15
#define MX 100

void imprimirVetor(float *pv, unsigned int qt);

int main(){
    float v[TAM];

    srand(time(NULL));

    for(int i=0; i<TAM; i++){
        v[i] = ((float) rand()/ RAND_MAX) * (MX-1);
    }

    imprimirVetor(v, TAM);

    return 0;


}

void imprimirVetor(float *pv, unsigned int qt){
    for (int k=0; k<qt; k++){
        printf("[%p] %.2f\n",pv+k, *(pv+k));
    }
}