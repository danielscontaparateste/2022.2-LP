#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if (argc!=2){
        printf("Use: \n\t\t %s <nomeDoUsuario>\n\n",argv[0]);
        exit(1);
    }

    printf("Oi, %s\n", argv[1]);

    return 0;

}

