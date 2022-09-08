#include <stdio.h>

int main(){
    int a;
    int b;
    float r;

    printf("Digite o primeiro valor inteiro: \n");
    scanf("%d",&a);

    printf("Digite o segundo valor inteiro: \n");
    scanf("%d",&b);

    r = (float)a /b;

    printf("Resultado: %f\n",r);

    return 0;
}