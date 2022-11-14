/* Codigo de autoria dos alunos Elias e Rai no desafio "interseção" em sala de aula */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int *alocaVetor(int*, int);
int *realocaVetor(int*, int);
void sorteiaVetor(int*, int);
int estaContido(int, int*, int);
int *fazIntercessao(int*, int*, int*, int, int, int*);
void imprimeVetor(int*, int);

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("ERRO | Use: %s [número > 0] [número > 0]\n", argv[0]);
    exit(1);
  }
  
  int *vetor1 = NULL;
  int *vetor2 = NULL;
  int *intercessao = NULL;
  int tam_vetor1 = atoi(argv[1]);
  int tam_vetor2 = atoi(argv[2]);
  int tam_intercessao = MAX;
  
  srand(time(NULL));
  
  vetor1 = alocaVetor(vetor1, tam_vetor1);
  vetor2 = alocaVetor(vetor2, tam_vetor2);
  intercessao = alocaVetor(intercessao, tam_intercessao);
  
  sorteiaVetor(vetor1, tam_vetor1);
  sorteiaVetor(vetor2, tam_vetor2);
  intercessao = fazIntercessao(vetor1, vetor2, intercessao, tam_vetor1, tam_vetor2, &tam_intercessao);
  intercessao = realocaVetor(intercessao, tam_intercessao);

  printf("\nVetores sorteados\n");
  imprimeVetor(vetor1, tam_vetor1);
  imprimeVetor(vetor2, tam_vetor2);
  
  printf("\nIntercessão de vetores\n");
  imprimeVetor(intercessao, tam_intercessao);

  free(vetor1);
  free(vetor2);
  free(intercessao);
  
  return 0;
}

int *alocaVetor(int *vetor, int tam){
  vetor = malloc(tam * sizeof(int));
  if(!vetor){
    printf("ERRO (2) | Memória insuficiente!\n");
    exit(1);
  }
  return vetor;
}

int *realocaVetor(int *vetor, int novo_tam){
  vetor = realloc(vetor, novo_tam *sizeof(int));
  if(!vetor){
    printf("ERRO (2) | Memória insuficiente!\n");
    exit(2);
  }
  return vetor;
}

void sorteiaVetor(int *vetor, int tam){
  for(int i = 0; i < tam; i++){
    *(vetor + i) = rand() % MAX;
  }
}

int estaContido(int valor, int *vetor, int tam){
  int contido = 0;
  for(int i = 0; i < tam; i++){
    if(valor == *(vetor + i)){
      contido++;
      break;
    }
  }
  return contido;
}

int *fazIntercessao(int *vetor1, int *vetor2, int *intercessao, int tam_vetor1, int tam_vetor2, int *tam_intercessao){
  int p = 0;
  for(int i = 0; i < tam_vetor1; i++){
    for(int j = 0; j < tam_vetor2; j++){
      if(*(vetor1 + i) == *(vetor2 + j) && !(estaContido(*(vetor1 + i), intercessao, p))){
        *(intercessao + p) = *(vetor1 + i);
        p++;
      }
    }
  }
  *tam_intercessao = p;
  return intercessao;
}

void imprimeVetor(int *vetor, int tamanho){
  printf("[");
  for(int i = 0; i < tamanho; i++){
    printf(" %d ", *(vetor + i));
  }
  printf("]\n");
}