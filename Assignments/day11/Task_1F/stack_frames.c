#include <stdio.h>

void level2(int b) {
    int l2 = 200;
    printf("Inside level2: b = %d, l2 = %d\n", b, l2);
}

void level1(int a) {
    int l1 = 100;
    level2(a + 10);
    printf("Inside level1: a = %d, l1 = %d\n", a, l1);
}

int main() {
    int m = 50;
    level1(m);
    return 0;
}
