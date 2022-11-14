#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int *pd, int qtd, int inicial, int qtdFaixa);
void imprimirMatriz2(int *pd, int qnl, int qnc);

struct matrix{
    int qtdLinhas;
    int qtdColunas;
    int maxval;
    int *pDados;
};

int main(int argc, char **argv){
    struct matrix mat;

    if (argc!=4){
        printf("Formato:\n\t%s <qtdLinhas> <qtdColunas> <maxVal>\n\n",argv[0]);
        exit(1);
    }

    mat.qtdLinhas = atoi(argv[1]);
    mat.qtdColunas = atoi(argv[2]);
    mat.maxval = atoi(argv[3]);

    if (!(mat.pDados = malloc(mat.qtdLinhas * mat.qtdColunas * sizeof(int)) )){
        puts("Não há memória suficiente! \n");
        exit(2);
    }

    preencherVetor(mat.pDados, mat.qtdLinhas * mat.qtdColunas, 0, mat.maxval+1);
    
    imprimirMatriz2(mat.pDados, mat.qtdLinhas, mat.qtdColunas);

    free(mat.pDados);
    
    return 0;

}

void preencherVetor(int *pd, int qtd, int inicial, int qtdFaixa){
    srand(time(NULL));
    for (int k=0; k<qtd; k++){
        *(pd+k) = inicial + rand() % qtdFaixa;
    }
}

void imprimirMatriz2(int *pd, int qnl, int qnc){
    for (int k=0; k<qnl*qnc; k++){
        if (!(k%qnc)) printf("\n");
        printf("%3d ",*(pd+k));
    }
    printf("\n");
}