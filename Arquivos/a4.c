#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main(){

    double d[TAM];

    puts("Entre com os dados: ");
    for(int k=0; k<TAM; k++){
        scanf("%lf",&d[k]);
    }
    
    FILE *fp;

    fp = fopen("fwriteVetor.txt","w+b");
    if (fp==NULL){
        puts("Erro ao abrir o arquivo.");
        exit(2);
    }

    fwrite(d, sizeof(double), TAM, fp);
    
    rewind(fp);

    double dr; 
    
    puts("Dados lidos do arquivo: ");

    for (int k=0; k<TAM; k++){
        fread(&dr, sizeof(double), 1, fp);
    
        printf("double: %lf\n",dr);
    }

    fclose(fp);

    return 0;

}