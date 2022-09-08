#include <stdio.h>

int main(){
    int a = 10;
LOOP:
    printf("%d\n", a);
    a++;
    if (a < 20) {
        goto LOOP;
    }
    return 0;
}