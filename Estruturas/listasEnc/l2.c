#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
	int x;
	struct Node *prox;
};

void imprimir(struct Node *);
void inserir(int, struct Node *);

int main(){
	struct Node h;

	srand(time(NULL));

	//system("clear");

	h.prox = NULL;

	imprimir(&h);
	inserir(rand()%50, &h);
	imprimir(&h);
	inserir(rand()%50, &h);
	imprimir(&h);
	inserir(rand()%50, &h);
	imprimir(&h);

	return 0;
}

void imprimir(struct Node *p){
	struct Node *k;
	
	printf("---\n");
	for (k=p->prox; k!=NULL; k=k->prox){
		printf("%d\n",k->x);
	}

}

void inserir(int v, struct Node *p){
	struct Node *n;
	n = malloc(sizeof(struct Node));
	n->x = v;
	n->prox = p->prox;
	p->prox = n;
}
