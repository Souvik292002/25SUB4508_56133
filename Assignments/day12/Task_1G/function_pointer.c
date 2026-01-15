#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

void operation(int (*func)(int, int), int x, int y) {
    int result = func(x, y);
    printf("Result = %d\n", result);
}

int main() {
    operation(add, 10, 5);
    operation(subtract, 10, 5);
    operation(multiply, 10, 5);
    operation(divide, 10, 5);
    return 0;
}
