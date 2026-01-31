#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <string.h>

/* Must match syscall number used in kernel */
#define SYS_reverse_string 548

int main() {
    char *input;
    char *output;
    size_t size = 256;

    /* Allocate memory dynamically */
    input = (char *)malloc(size);
    output = (char *)malloc(size);

    if (!input || !output) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Enter a string: ");
    fgets(input, size, stdin);

    /* Invoke custom system call */
    if (syscall(SYS_reverse_string, input, output) < 0) {
        perror("System call failed");
        free(input);
        free(output);
        return 1;
    }

    printf("Reversed string: %s\n", output);

    /* Free allocated memory */
    free(input);
    free(output);

    return 0;
}
