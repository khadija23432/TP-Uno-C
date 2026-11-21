#include <stdio.h>
int a, b, c;
int main() {
printf("entrez un nombre: ");
scanf("%d", &a);
printf("entrez un nombre: ");
scanf("%d", &b);
c=a;
a=b;
b=c;
printf("les valeurs echangées sont:%d %d \n", a, b);
}
