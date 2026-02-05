#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/syscall.h>

#define __NR_reverse_string 548

int main() {
    char input[256];
    char output[256];
    int len;

    scanf("%255s", input);
    len = strlen(input);

    long ret = syscall(__NR_reverse_string, input, output, len);

    if (ret < 0) {
        perror("syscall failed");
        return 1;
    }

    write(1, "Reversed: ", 10);
    write(1, output, len);
    write(1, "\n", 1);

    return 0;
}
