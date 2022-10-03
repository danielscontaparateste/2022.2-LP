#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3
#define MX 100

int main(){
    int mat[TAM][TAM], menor, soma=0;

    srand(time(NULL));

    // Entrada de Dados
    for (int k=0; k<TAM; k++){
        for (int j=0; j<TAM; j++){
            mat[k][j] = rand() % MX;
        }
    }

    // Processamento
    menor = mat[0][0];
    // for (int k=0; k<TAM; k++){
    //     for (int j=0; j<TAM; j++){
    //         if (k==j){
    //             // soma += mat[k][j];
    //             if (menor>mat[k][j]){
    //                 menor = mat[k][j];
    //             }
    //         } 
    //     }
    // }

    for(int k=0; k<TAM; k++){
        soma += mat[k][k];
        menor = (menor > mat[k][k])?mat[k][k]:menor;
    }


    // Saída
    for (int k=0; k<TAM; k++){
        for (int j=0; j<TAM; j++){
            printf("%3d ",mat[k][j]);
        }
        printf("\n");
    }
    printf("Soma da diagonal principal: %d\n Menor valor da diagonal principal: %d\n",soma, menor);


    return 0;

}