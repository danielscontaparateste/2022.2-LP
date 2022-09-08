#include <stdio.h>

int main(){

	char ch = 'a';
	int v = -10; // mesma coisa de signed int
	unsigned int xd = 20;
	float f;
	unsigned char xch;
	long int nd;
	long long int nnd;


	printf("dados: %d %c %u\n",v,ch,xd);


	printf("Tamanho do char: %lu\n",sizeof(ch));
	printf("Tamanho do unsigned char: %lu\n",sizeof(xch));
	printf("Tamanho do int: %lu\n",sizeof(v));
	printf("Tamanho do unsigned int: %lu\n",sizeof(xd));
	printf("Tamanho do float: %lu\n",sizeof(f));
	printf("Tamanho do long int: %lu\n",sizeof(nd));
	printf("Tamanho do long long int: %lu\n",sizeof(nnd));
	printf("Tamanho do double: %lu\n",sizeof(double));

	return 0;
}