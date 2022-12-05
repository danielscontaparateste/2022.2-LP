#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "util.h"

int main(int argc, char *argv[]){
	int op, a, b;

	if(argc!=3){
		printf("Formatoo: \n\t %s <n1> <n2>\n",argv[0]);
		exit(1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	imprimirMenu();
	scanf("%d", &op);

	switch(op){
		case 1:
			printf("%d + %d = %d\n",a,b, somar(a,b));
		break;
		case 2:
			printf("%d - %d = %d\n",a,b, subtrair(a,b));
		break;
		case 3:
			printf("%d * %d = %d\n",a,b, multiplicar(a,b));
		break;
		case 4:
			printf("%d / %d = %.1f\n",a,b, dividir(a,b));
		break;
		default:
			puts("Opção Inválida. Tente novamente.");

	}

	return 0;
}