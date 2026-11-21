#include <stdio.h>

int algo1(int a, int b) {
    int r=0;
    a = a + 1;
    b = b * a;
    r= b - a;
    return r;
}
int algo2(int x, int y) {
    int a=1;
    int b=1;
    int c=1;
    a = a * (x + y);
    b = b * (y + x);
    c = c * (x + y);
    return (a * b) - c;
}
int algo3(int x, int y) {
    int z = algo1(x, y);
    return algo2(x - y, z);
}
int main() {
    int r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12;
    r1 =algo1(1, 0);
    printf("%d\n", r1);
    r2 = algo1(0, 5);
    printf("%d\n", r2);
    r3 = algo1(-1, 5);
    printf("%d\n", r3);
    r4 = algo2(3, 3);
    printf("%d\n", r4);
    r5 = algo2(3, 0);
    printf("%d\n", r5);
    r6 = algo2(0, 3);
    printf("%d\n", r6);
    r7 = algo2(5, 2);
    printf("%d\n", r7);
    r8 = algo2(0, 1);
    printf("%d\n", r8);
    r9 = algo3(0, 0);
    printf("%d\n", r9);
    r10 = algo3(1, 2);
    printf("%d\n", r10);
    r11 = algo3(0, 3);
    printf("%d\n", r11);
    r12 = algo3(0, 5);
    printf("%d\n", r12);    
}





