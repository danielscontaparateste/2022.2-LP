#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15
#define MX 100

int main(){
    int v[TAM];

    srand(time(NULL));

    for(int i=0; i<TAM; i++){
        v[i] = rand() % MX;
    }

    puts("Vetor não ordenado");
    for(int i=0; i<TAM; i++){
        printf("%d ",v[i]);
    }

    printf("\n");
    
    // Processamento
    int t;
    for (int k=0; k<TAM-1; k++){
        for (int j=k+1; j<TAM; j++){
            if (v[k]>v[j]){
                t = v[k];
                v[k] = v[j];
                v[j] = t;
            } 
        }
    }

    puts("Vetor ordenado");
    for(int i=0; i<TAM; i++){
        printf("%d ",v[i]);
    }

    printf("\n");
    

    return 0;


}