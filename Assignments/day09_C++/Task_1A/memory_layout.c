#include <stdio.h>
#include <stdlib.h>

/* Global variables */
int global_var = 100;
static int static_global = 200;
const int global_const = 300;

int main() {

    /* Local variables */
    int local_var = 10;
    static int static_local = 20;
    const int const_var = 30;

    /* Heap variable */
    int *heap_ptr = (int *)malloc(sizeof(int));
    *heap_ptr = 40;

    printf("Program paused for GDB observation\n");

    free(heap_ptr);
    return 0;
}
