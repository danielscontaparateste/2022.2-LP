#include <stdio.h>
#include <stdlib.h>

int main(){

    double d = 12.34;
    int i = 10;

    FILE *fp;

    fp = fopen("fwrite.txt","w+b");
    if (fp==NULL){
        puts("Erro ao abrir o arquivo.");
        exit(2);
    }

    fwrite(&d, sizeof(double), 1, fp);
    fwrite(&i, sizeof(int), 1, fp);

    rewind(fp);


    double dr;
    int ir;
    
    fread(&dr, sizeof(double), 1, fp);
    fread(&ir, sizeof(int), 1, fp);

    printf("double: %lf, int: %d\n",dr, ir);

    fclose(fp);

    return 0;

}