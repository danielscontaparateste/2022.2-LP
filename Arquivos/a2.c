#include <stdio.h>
#include <stdlib.h>

#define TAM 80

int main(){
    FILE *fp;
    char ch;

    fp = fopen("chars.txt","w+");

    if (fp==NULL){
        puts("Erro ao abrir o arquivo");
        exit(1);
    }

    // Escrita dos dados
    do{
        puts("Digite um char ");
        ch = getchar();
        fflush(stdin);
        putc(ch, fp);
        putc('\n', fp);
    }while(ch != '$');

    rewind(fp);

    puts("=====");
    puts("Dados do arquivo: ");
    //Leitura dos dados 
    int chr;
    while ((chr = getc(fp)) != EOF){
        putc(chr, stdout);
    }

    fclose(fp);

    return 0;

}
