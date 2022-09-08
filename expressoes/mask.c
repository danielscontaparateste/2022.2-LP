#include <stdio.h>

int main(){

	unsigned char x = 10; // 0000 1010
	unsigned char mask = 0x05; //0000 0101
	unsigned char mask2 =  0xfd; //253; // 1111 1101; 

	unsigned char y;

	// y = x | mask; // Ligar bits
	y = x & mask2; // Desligar bits

	printf("%hhu\n",y);


	return 0;
}