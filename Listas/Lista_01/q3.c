#include <stdio.h>

int main(){
    float f;

    // printf("Digite um valor: \n");
    puts("Digite um valor");

    scanf("%f",&f);

    printf("Valor recebido: %.1f\n",f);

    return 0;     
}