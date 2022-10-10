//Escreva um programa que adicione dois números usando ponteiros. Al ́em do valor da soma, imprima tamb ́em o endere ̧co de mem ́oria onde o valor resultante dessa soma est ́a armazenado.

#include <stdio.h>

void somar(int *px, int *py, int *ps);

int main(){
    int x, y, s;
    int *qx = &x, *qy = &y, *qs = &s; 

    
    printf("Digite os valores: \n");
    // scanf("%d%d",&x,&y);
    scanf("%d%d",qx,qy);

    // somar(&x, &y, &s);
    somar(qx, qy, qs);

    // printf("O resultado de [%p] %d + [%p] %d é: [%p] %d\n",&x, x,&y, y,&s, s);
    printf("O resultado de [%p] %d + [%p] %d é: [%p] %d\n\n",qx, x,qy, y,qs, s);

    return 0;
}


void somar(int *px, int *py, int *ps){
    *ps = *px + *py;
}