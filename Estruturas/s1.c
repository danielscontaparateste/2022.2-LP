#include <stdio.h>

#define TC 3
#define TD 50



struct UF{
    char codigo[TC];
    char descricao[TD];
};

int main(){
    struct UF f1;

    puts("Digite o codigo da UF: ");
    fgets(f1.codigo,TC,stdin);

    fflush(stdin);

    puts("Digite a descricao da UF: ");
    fgets(f1.descricao,TD,stdin);

    puts("Dados digitados");

    printf("Codigo: %s\n",f1.codigo);
    printf("Descricao: %s\n",f1.descricao);

    return 0;

}