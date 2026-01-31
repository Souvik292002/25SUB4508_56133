/*Q4. 
C Program to Remove all Characters in Second String which are present in First String
i/p
Bhima shankar is a C programme
o/p
Bhima snkr is a C programme*/

#include <stdio.h>
#include <string.h>

int main() {

    char first[100];     // First string (characters to remove)
    char second[200];    // Second string (original sentence)

    // Read first string
    fgets(first, sizeof(first), stdin);

    // Read second string
    fgets(second, sizeof(second), stdin);

    /*
        Remove newline character added by fgets
    */
    first[strcspn(first, "\n")] = '\0';
    second[strcspn(second, "\n")] = '\0';

    /*
        visited array to mark characters present in first string
        ASCII size = 256
    */
    int visited[256] = {0};

    // Mark all characters of first string
    for (int i = 0; first[i] != '\0'; i++) {
        visited[(unsigned char)first[i]] = 1;
    }

    int index = 0;   // Index for modified second string

    /*
        Traverse second string
        Copy only those characters NOT present in first string
    */
    for (int i = 0; second[i] != '\0'; i++) {

        // If character is not marked, keep it
        if (visited[(unsigned char)second[i]] == 0) {
            second[index] = second[i];
            index++;
        }
    }

    // Null terminate the modified string
    second[index] = '\0';

    // Print the result
    printf("%s", second);

    return 0;   // End of program
}
