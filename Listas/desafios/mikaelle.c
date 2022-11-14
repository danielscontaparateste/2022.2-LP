/* Codigo de autoria da aluna Mikaelle no desafio "interseção" em sala de aula */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define INI 1
#define MX 10

void preencherVetor(int *, int, int, int);
void imprimirVetor(int *, int);
void interVetor(int *, int *, int *, int , int);
void tiraRepeticao(int *, int);
void bubblesort(int *, int);
int tamanhoPont(int *, int *, int, int);

int main(int argc, char *argv[]) {
  int *pa=NULL, *pb=NULL, *pc=NULL;
  int a, b, qnt;
  
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  
  srand(time(NULL));

  if (!(pa = malloc(a * sizeof(int)))){
    exit(1);
  }
  if (!(pb = malloc(b * sizeof(int)))){
    exit(2);
  }

  preencherVetor(pa, a, INI, MX);
  preencherVetor(pb, b, INI, MX);
  printf("\n");
  
  bubblesort(pa, a);
  bubblesort(pb, b);
  
  imprimirVetor(pa, a);
  printf("\n");
  imprimirVetor(pb, b);

  sleep(1);
  
  tiraRepeticao(pa, a);
  tiraRepeticao(pb, b);
  
  sleep(1);
  
  qnt = tamanhoPont(pa,pb,a,b);
  printf("\n\nTamanho da intersecção: %d\n",qnt);

  if (!(pc = malloc(qnt * sizeof(int)))){
    exit(3);
  }
  sleep(1);
  
  interVetor(pa, pb, pc, a, b);
  printf("\nVetor da intersecção A ∩ B:\n\n");
  imprimirVetor(pc, qnt);
  return 0;
}

void preencherVetor(int *pd, int qtd, int inicial, int qtdFaixa){
  
  for (int k=0; k<qtd; k++){
    *(pd+k) = inicial + rand() % qtdFaixa;
  }
}

void imprimirVetor(int *pd, int qtd){
    for (int k=0; k<qtd; k++){
        printf("[%p] %d\n",pd+k,*(pd+k));
    }
}

void bubblesort(int *vet, int tam){
  for(int i = 0; i < tam-1; i++){
    for(int j = i+1; j < tam; j++){
       if(*(vet + j) < *(vet + i)){
         *(vet + i) ^= *(vet + j);
         *(vet + j) ^= *(vet + i);
         *(vet + i) ^= *(vet + j);
          }
        }
      }
  }

int tamanhoPont(int *pa, int *pb, int a, int b){
  int i, j, qnt=0;
  for (i = 0; i<a; i++){
    for(j = 0;j<b; j++){
      if(*(pa+i) == *(pb+j)){
        qnt++;
      }
    }
  }
  return qnt;
}

void interVetor(int *vet1, int *vet2, int *vet3, int a, int b){
  int k=0;
  for (int i = 0; i<a; i++){
    for (int j = 0; j<b; j++){
      if(*(vet1+i) == *(vet2+j)){
        *(vet3+k) = *(vet2+j);
        k++;
      }
      
    }
  }
}

void tiraRepeticao(int *pc, int tam){
  int i, j, k;
  
  // Remove valores duplicados //
  for(i = 0; i < tam; i++){
    for(j = i + 1; j < tam;){
        if(*(pc+j) == *(pc+i)){
          for(k = j; k < tam; k++)
            *(pc+k) = *(pc+k+1);
            tam--;
          }
        else{
          j++;
            }
        }
    }
    // Ponteiro após remoção de duplicatas //
    printf("\nSem repetições: ");
    for( i = 0; i<tam; i++){ 
        printf("%d ", *(pc+i));   
     }
  }