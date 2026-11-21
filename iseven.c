#include <stdio.h>
#include "iseven.h"
#include "askeven.c"
void iseven(){
    int numero;
    if (numero % 2 == 0) {
        printf("%d est un nb pair\n", numero);
        return 1;
    } else {
        printf("c'est impair\n");
        return 0;
    }
}