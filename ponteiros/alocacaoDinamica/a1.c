#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INI 0
#define MX 100

void imprimirVetor(int *, int);
void preencherVetor(int *, int, int, int);

int main(int argc, char **argv){
    unsigned int qtd;
    int *pv = NULL;

    if(argc!=2){
        printf("Use:\n\t\t%s <qtdElementos>\n\n",argv[0]);
        exit(1);
    }

    qtd = atoi(argv[1]);

    // if (!(pv = malloc(qtd * sizeof(int)))){
    //     puts("Erro na alocacao de memoria.");
    //     exit(2);
    // }

    // if (!(pv = calloc(qtd, sizeof(int)))){
    //     puts("Erro na alocacao de memoria.");
    //     exit(2);
    // }

    if (!(pv = realloc(NULL, qtd * sizeof(int)))){
        puts("Erro na alocacao de memoria.");
        exit(2);
    }

    preencherVetor(pv, qtd, INI, MX);
    imprimirVetor(pv, qtd);

    // Realocacao de Memoria
    int qtdn;
    printf("Digite o novo tamanho do vetor: \n");
    scanf("%d",&qtdn);
    
    if (!(pv = realloc(pv, qtdn*sizeof(int) ))){
        puts("Erro na alocacao de memoria.");
        exit(3);
    }

    if (qtdn>qtd) preencherVetor(pv+qtd, qtdn, INI, MX);

    puts("=======");
    imprimirVetor(pv, qtdn);
    // imprimirVetor(pv, 10);
 
    free(pv);

    return 0;
}



void preencherVetor(int *pd, int qtd, int inicial, int qtdFaixa){
    srand(time(NULL));
    for (int k=0; k<qtd; k++){
        *(pd+k) = inicial + rand() % qtdFaixa;
    }
}


void imprimirVetor(int *pd, int qtd){
    for (int k=0; k<qtd; k++){
        printf("[%p] %d\n",pd+k,*(pd+k));
    }
}

