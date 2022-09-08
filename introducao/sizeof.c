#include <stdio.h>

int main(){
    char c = 65;

    //printf("Valor: %c\n",c); 
    printf("char: %lu bytes\n",sizeof(c));

    printf("int: %lu bytes\n",sizeof(int));
    printf("long int: %lu bytes\n",sizeof(long int));
    printf("long unsigned int: %lu bytes\n",sizeof(long unsigned int));
    
    return 0;
}