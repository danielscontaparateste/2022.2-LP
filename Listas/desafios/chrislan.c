/* Codigo de autoria do aluno Chrislan no desafio "interseção" em sala de aula */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 11
#define INI 0

int *alocar(int *, int);
void gerarvetor(int *, int, int, int);
void imprimirvetor(int *, int);
void ordenarvetor(int *, int);
void tirarrepeticao(int *, int);
void interseccao(int *, int *, int, int);

int main(int argc, char *argv[]) {
  int *v1 = NULL, *v2 = NULL;
  int n, m;
  srand(time(NULL));
  if (argc != 3) {
    printf("Type \n\t %s <qtElements1> <qtElements2>\n", argv[0]);
    exit(2);
  }
  if ((n=atoi(argv[1])) <= 0 || ((m=atoi(argv[2])) <= 0)) {
    printf("\t\t<qtElemets1> > 0 & <qtElements2> > 0\n");
    exit(3);
  }
  
  v1 = alocar(v1, n);
  
  v2 = alocar(v2, m);
  
  puts("First generated vector");
  gerarvetor(v1, n, INI, MAX);
  imprimirvetor(v1, n);
  puts("Second generated vector");
  gerarvetor(v2, m, INI, MAX);
  imprimirvetor(v2, m);

  puts("Intersection Vector");
  interseccao(v1, v2, n, m);
  
  free(v1);
  free(v2);
  return 0;
}
int *alocar(int *v, int qtd) {
  if (!(v = malloc(sizeof(int) * qtd))) {
    puts("ERROR. Insufficient memory");
    exit(1);
  }
  return v;
}

void gerarvetor(int *v, int qtd, int ini, int max) {
  for (int i = 0; i < qtd; i++) {
    *(v + i) = (rand() % max) + ini;
  }
}

void imprimirvetor(int *v, int qtd) {
  printf("[ ");
  for (int i = 0; i < qtd; i++) {
    printf("%d ", *(v + i));
  }
  printf("]\n\n");
}

void ordenarvetor(int *v, int qtd) {
  for (int i = qtd - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (*(v + j) > *(v + j + 1)) {
        *(v + j) ^= *(v + j + 1);
        *(v + j + 1) ^= *(v + j);
        *(v + j) ^= *(v + j + 1);
      }
    }
  }
}

void tirarrepeticao(int *v, int qtd) {
  int *ordem = NULL;
  int cont = 0;
  for (int i = 0; i < qtd; i++) {
    if (*(v + i) != *(v + i + 1) || (i == qtd - 1))
      cont++;
  }
  ordem = alocar(ordem, cont);
  cont = 0;
  for (int i = 0; i < qtd; i++) {
    if (*(v + i) != *(v + i + 1) || (i == qtd - 1)) {
      *(ordem + cont) = *(v + i);
      cont++;
    }
  }
  imprimirvetor(ordem, cont);
  free(ordem);
}

void interseccao(int *v1, int *v2, int n, int m) {
  int *inter = NULL;
  int cont = 0;
  for (int j = 0; j < n; j++) {
    for (int k = 0; k < m; k++) {
      if (*(v1 + j) == *(v2 + k)) {
        cont++;
      }
    }
  }
  inter = alocar(inter, cont);
  cont = 0;
  for (int j = 0; j < n; j++) {
    for (int k = 0; k < m; k++) {
      if (*(v1 + j) == *(v2 + k)) {
        *(inter + cont) = *(v1 + j);
        cont++;
      }
    }
  }
  ordenarvetor(inter, cont);
  tirarrepeticao(inter, cont);
  free(inter);
}