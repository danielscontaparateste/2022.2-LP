#include <stdio.h>

int main(){
    int a = 10;
    // Uso do GOTO
LOOP:
    a += 1; // a = a + 1; a++;
    do{
        if (a == 15){        
            goto LOOP;
        }
        printf("%d\n", a++);

    } while (a < 20);
    // // CONTINUE
    // printf("=====\n");
    // for (a = 10; a < 20; a++) {
    //     if (a == 15)
    //         continue;
    //     printf("%d\n", a);
    // }

    // printf("=====\n");

    // for (a = 10; a < 20; a++)
    // {
    //     if (a != 15)
    //         printf("%d\n", a);
    // }

    return 0;
}