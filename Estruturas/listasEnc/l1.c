#include <stdio.h>

struct Node{
	int x;
	struct Node *prox;
};

void imprimir(struct Node *);

int main(){
	struct Node n1, n2, n3; // h;

	// h.prox = &n1;

	n1.x = 10;
	n1.prox = &n2;

	n2.x = 20;
	n2.prox = &n3;

	n3.x = 30;
	n3.prox = NULL;

	imprimir(&n1);

	return 0;
}

void imprimir(struct Node *p){
	struct Node *k;
	
	for (k=p; k!=NULL; k=k->prox){
		printf("%d\n",k->x);
	}

}
