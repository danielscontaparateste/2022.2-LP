#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD 1000
#define MX 11
#define INI 0

int main(){
    int x[QTD];
    int soma = 0; 
    float media; 

    srand(time(NULL));

    //Entrada de Dados
    puts("Entre com os dados: ");
    for(int i=0; i<QTD; i++){
        // scanf("%d",&x[i]);
        x[i] = rand() % MX + INI;
    } 

    //Processamento
    for(int i=0; i<QTD; i++){
        soma += x[i]; // soma = soma + x[i];
    }
    media = ( (float) soma) / QTD;

    // Saída
    puts("----");
    for(int i=0; i<QTD; i++){
        printf("%d\n",x[i]);
    } 
    puts("----");
    printf("Media: %.2f\n",media);

    return 0;

}