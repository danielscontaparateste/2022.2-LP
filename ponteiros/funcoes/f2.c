#include <stdio.h>
#include <stdlib.h>

#define QTD_OPERACOES 3

void somar(int, int);
void multiplicar(int, int);
void dividir(int, int);

int main(int argc, char *argv[]){
    void (*pFunc[])()= {somar, multiplicar, dividir};
    int n, z;

    if (argc!=2){
        printf("Uso:\n\t %s operacao\n\n",*argv);
        exit(1);
    }

    int codigoOperacao = atoi(argv[1]);

    if ( (codigoOperacao < 0) || (codigoOperacao >= QTD_OPERACOES)){
        puts("Operacao nao implementada");
        exit(2);
    }


    puts("Digite um número: ");
    scanf("%d",&n);
    puts("Digite um número: ");
    scanf("%d",&z);

    
    (*pFunc[codigoOperacao])(n,z);
    

    return 0;
}

void somar(int x, int y){
    printf("Resultado: %d\n",x+y);
}

void multiplicar(int x, int y){
    printf("Resultado: %d\n",x*y);
}

void dividir(int x, int y){
    printf("Resultado: %.2f\n",((float) x)/y);
}