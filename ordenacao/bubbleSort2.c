#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50
#define QTD 100

void imprimirVetor(int x[], int t);

int main(){
    // int v[TAM] = {2, 1, 4, 6, 0}; 
    int v[TAM]; 
    
    int aux, naoOrdenado, count=-1;

    srand(time(NULL));

    //Entrada
    for (int k=0; k<TAM; k++){
        v[k] = rand() % QTD;
    }

    puts("Vetor não ordenado");
    imprimirVetor(v, TAM);

    // Processamento
    // for(int i=1; i<TAM; i++){
    do{    
        naoOrdenado=0;
        count++; // Quantidade de iteracoes.
        for (int k=0; k<TAM-1; k++){
            if (v[k]>v[k+1]){
                // aux = v[k];
                // v[k] = v[k+1];
                // v[k+1] = aux;
                
                v[k] = v[k]^v[k+1];
                v[k+1] = v[k]^v[k+1]; 
                v[k] = v[k]^v[k+1];    
                
                naoOrdenado=1;
            }
        }
    }while(naoOrdenado);

    // Saída
    puts("Vetor ordenado");
    imprimirVetor(v, TAM);
    printf("Ordenado em %d iteracoes. \n\n",count);

    return 0;
}

void imprimirVetor(int x[], int t){
    for (int k=0; k<t; k++){
        printf("%d ",x[k]);
    }
    printf("\n");
}