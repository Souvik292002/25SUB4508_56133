#include <stdio.h>

void modifyValue(int **pptr) {
    **pptr = 200;
}

int main() {
    int x = 100;
    int *ptr = &x;
    int **pptr = &ptr;

    printf("Before modification: x = %d\n", x);
    modifyValue(pptr);
    printf("After modification: x = %d\n", x);

    return 0;
}
