#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define MX 10

struct coord{
    int x;
    int y;
};

int main(){
    struct coord ps[TAM];

    srand(time(NULL));

    for (int k=0; k<TAM; k++){
        ps[k].x = rand() % MX;
        ps[k].y = rand() % MX;
    }

    for (int k=0; k<TAM; k++){
        printf("[%d] x : %d\n",k,ps[k].x);
        printf("[%d] y : %d\n",k,ps[k].y);
        puts("---");
    }

    return 0;

}