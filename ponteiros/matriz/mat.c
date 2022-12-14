#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int *, int, int, int);
void imprimirMatriz(int *, int, int);
void imprimirMatriz2(int *, int, int);
void imprimirVetor(int *, int );
int getValorMatriz(int *,int, int, int);

int main(){

    int *pData = NULL;
    int nl, nc;

    puts("Digite a quantidade de linhas:");
    scanf("%d",&nl);

    puts("Digite a quantidade de colunas:");
    scanf("%d",&nc);

    pData = malloc(nl * nc * sizeof(int));

    if (!pData){
        puts("Erro. Tente quantidade de linhas e colunas diferentes.");
        exit(1);
    }

    preencherVetor(pData, nl*nc, 0, 100);
    puts("--------");
    imprimirVetor(pData, nl * nc);
    puts("-------- Função imprimirMatriz --------");
    imprimirMatriz(pData, nl, nc);
    puts("-------- Função imprimirMatriz2 --------");
    imprimirMatriz2(pData, nl, nc);

    puts("--------");

    int a, b;
    puts("Digite a coordenada do valor que deseja recuperar: ");
    puts("linha: ");
    scanf("%d",&a);
    puts("coluna: ");
    scanf("%d",&b);

    /* Exercício: implemente uma verificação dos limites de a e b recebidos */

    printf("Valor recuperado %d\n",getValorMatriz(pData,a,b,nc));

    free(pData);

    return 0;

}



void preencherVetor(int *pd, int qtd, int inicial, int qtdFaixa){
    srand(time(NULL));
    for (int k=0; k<qtd; k++){
        *(pd+k) = inicial + rand() % qtdFaixa;
    }
}

void imprimirMatriz(int *pd, int qnl, int qnc){
    for (int k=0; k<qnl; k++){
        for (int j=0; j< qnc; j++){
            printf("%3d ",*(pd + qnc * k + j));
        }
        printf("\n");
    }
}

void imprimirMatriz2(int *pd, int qnl, int qnc){
    for (int k=0; k<qnl*qnc; k++){
        if (!(k%qnc)) printf("\n");
        printf("%3d ",*(pd+k));
    }
    printf("\n");
}

void imprimirVetor(int *pd, int qtd){
    for (int k=0; k<qtd; k++){
        printf("[%p] %d\n",pd+k,*(pd+k));
    }
}

int getValorMatriz(int *pd,int lin, int col, int qnc){
    return *(pd + (lin-1)*qnc + (col-1));
}