#include <stdio.h>
int a, b;
int main() {
printf("entrez un nombre: ");
scanf("%d", &a);
printf("entrez un nombre: ");
scanf("%d", &b);
a=a+b;
b=a-b;
a=a-b;
printf("les valeurs echangées sont: %d %d \n", a, b);
}
