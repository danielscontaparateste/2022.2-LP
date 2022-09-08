#include <stdio.h>

int main(){

	int a;
	unsigned int b;

	a = 2147483647;
	b = 4294967295;

	printf("Tamanho: %ld\n", sizeof(a));

	// printf("a = %d, b = %d\n\n", a, b);

	printf("a = %d | a++ = %d\n", a, a + 1);
	printf("b = %u | b++ = %u\n", b, b + 1);

	return 0;
}