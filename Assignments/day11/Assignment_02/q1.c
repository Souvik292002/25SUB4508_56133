#include <stdio.h>    // For printf() and scanf()
#include <string.h>   // For strtok() - used to split strings
#include <stdlib.h>   // For atoi() - converts string to integer

int main() {

    // Character arrays to store the input strings
    // In C, strings are stored as arrays of characters
    char list1[200], list2[200];

    // Integer arrays to store extracted numbers
    int a[100], b[100];

    // Counters to keep track of number of elements in each array
    int n1 = 0, n2 = 0;

    // Read first comma-separated list as a string
    // Example input: 7,8,29
    scanf("%s", list1);

    // Read second comma-separated list as a string
    // Example input: 29,8,8,8,7,7,8,7
    scanf("%s", list2);

    // strtok() splits the string using "," as delimiter
    // It returns a pointer to the first token
    char *token = strtok(list1, ",");

    // Loop until no more tokens are found
    while (token != NULL) {

        // Convert token (string) to integer and store in array
        // atoi() works like Integer.parseInt() in Java
        a[n1++] = atoi(token);

        // Get the next token from the same string
        token = strtok(NULL, ",");
    }

    // Start tokenizing the second list
    token = strtok(list2, ",");

    while (token != NULL) {

        // Convert token to integer and store in second array
        b[n2++] = atoi(token);

        // Move to the next token
        token = strtok(NULL, ",");
    }

    // For each number in the first list
    for (int i = 0; i < n1; i++) {

        // Initialize count for current number
        int count = 0;

        // Compare with all numbers in second list
        for (int j = 0; j < n2; j++) {

            // If numbers match, increase count
            if (a[i] == b[j]) {
                count++;
            }
        }

        // Print result in exact required format: N-C
        printf("%d-%d\n", a[i], count);
    }

    // Return 0 indicates successful program execution
    return 0;
}
