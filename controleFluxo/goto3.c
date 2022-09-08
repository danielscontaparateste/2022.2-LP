#include <stdio.h>

int main(){
    int a = 10;

    while(a<100){
        if (a==15){
            goto MX;
            // break;
        }
        a++;
    }

    printf("Antes do rotulo\n");

MX:
    printf("%d\n", a);
   
    return 0;
}