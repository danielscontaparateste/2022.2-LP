#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void multiplicar(int, int, int *);
void dividir(int, int, int *);
void subtrair(int, int, int *);
void somar(int, int, int *);

void calcular( void (*pF) (), int a, int b, int *pR);

typedef void (*Func)();

int main(int argc, char *argv[]){
	
	if (argc!=4){
		printf("Formato\n\t\t%s <valor1> <valor2> <codOper>\n",argv[0]);
		exit(1);
	}

	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	int op = atoi(argv[3]); 
	int r;

    // void (*v[])()= {multiplicar, dividir, subtrair};
	Func v[] = {dividir, multiplicar, subtrair, somar};
	
	calcular( v[op], n1, n2, &r);
	printf("r = %d\n",r);

	return 0;
}

void multiplicar(int x, int y, int *z){
	*z = x * y;
}

void dividir(int x, int y, int *z){
	*z = x / y;
}

void subtrair(int x, int y, int *z){
	*z = x - y;
}

void somar(int x, int y, int *z){
	*z = x + y;
}

void calcular( void (*pF) (), int a, int b, int *pR){
	(*pF)(a,b,pR);
}
