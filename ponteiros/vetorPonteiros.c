#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 100 // Quant. de elementos na faixa de valores do vetor
#define INI 0

void imprimirVetor(int *, int);
void preencherVetor(int *, int, int, int);
int *getEndMenor(int *, int);
int *getEndMaior(int *, int);

int main(int argc, char *argv[]){
    int *pv = NULL, maior, menor;
    // int **pp = NULL; // 
    int *pp[2]; 
    
    // Validação se a quantidade de elementos do vetor foi fornecida por linha de execução.
    if (argc!=2){
        printf("Use:\n\t %s <qtdElementosVetor>\n\n",argv[0]);
        exit(1);
    }

    // Quantidade de elementos do vetor fornecida pelo usuário.
    int qtd = atoi(argv[1]);

    // Alocação dinâmica de memória
    if (! (pv = malloc(qtd * sizeof(int)) ) ) {
        puts("Não há memória. Tente outra vez.\n");
        exit(2);
    }

    // Obter dados
    preencherVetor(pv, qtd, INI, MX);
    
    // Mostrar dados
    imprimirVetor(pv, qtd);

    // Obtendo os endereços do menor de maior elemento no vetor.
    pp[0] = getEndMenor(pv, qtd);
    pp[1] = getEndMaior(pv, qtd);

    puts("Saída: \n");

    printf("[%p] : %d\n",pp[0],*pp[0]);
    printf("[%p] : %d\n",pp[1],*pp[1]);
    

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