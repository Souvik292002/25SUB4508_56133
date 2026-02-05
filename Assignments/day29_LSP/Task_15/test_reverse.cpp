#include <iostream>
#include <cstring>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>

// Must match the syscall number used in kernel
#define __NR_reverse_string 548

int main() {
    char *input = nullptr;
    char *output = nullptr;
    size_t len;

    try {
        // Allocate memory
        input = new char[256];
        output = new char[256];

        std::cout << "Enter a string: ";
        std::cin >> input;

        len = strlen(input);

        // Invoke custom system call
        long ret = syscall(__NR_reverse_string, input, output, len);

        // Error handling
        if (ret < 0) {
            perror("System call failed");
            delete[] input;
            delete[] output;
            return 1;
        }

        // Print result
        std::cout << "Reversed string: " << output << std::endl;
    }
    catch (...) {
        std::cerr << "Memory allocation failed" << std::endl;
        delete[] input;
        delete[] output;
        return 1;
    }

    // Free allocated memory
    delete[] input;
    delete[] output;

    return 0;
}
