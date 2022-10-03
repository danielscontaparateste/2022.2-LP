#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15
#define MX 100

int main(){
    float v[TAM], menor, maior;

    srand(time(NULL));

    for(int i=0; i<TAM; i++){
        v[i] = ((float) rand()/ RAND_MAX) * (MX-1);
    }

    menor = v[0];
    maior = v[0];
    for (int i=1; i<TAM; i++){
        menor = (menor>v[i])?v[i]:menor;
        maior = (maior<v[i])?v[i]:maior;
    }


    for(int i=0; i<TAM; i++){
        printf("%.2f ",v[i]);
    }
    printf("\n");
    printf("Menor: %.2f\nMaior: %.2f\n",menor,maior);

    return 0;


}