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
    for (int k=1; k<TAM; k++){
        for (int j=0; j<TAM-1; j++){
            if (v[j]>v[j+1]){
                t = v[j];
                v[j] = v[j+1];
                v[j+1] = t;
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