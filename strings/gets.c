#include <stdio.h>

#define TAM 10

//char *fgets(char *str, int n, FILE *stream)

int main(){
    char str[TAM];

    // scanf("%s",str);

    fgets(str,TAM,stdin);

    // gets(str);

    puts(str);

    puts("---");

    int i = 0;
    while(str[i]!='\0'){
        printf("%d\n",str[i]);
        i++;
    }

    return 0;

}