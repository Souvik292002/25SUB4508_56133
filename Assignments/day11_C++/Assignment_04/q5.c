/*Q5
alternativel merge two strings

i/p
Bhima
ABCDEOLM
o/p
BAhBiCmDaEOLM*/

#include <stdio.h>
#include <string.h>

int main() {

    char str1[100];    // First input string
    char str2[100];    // Second input string
    char result[200];  // Array to store merged result

    // Read first string
    scanf("%s", str1);

    // Read second string
    scanf("%s", str2);

    int i = 0;   // Index for str1
    int j = 0;   // Index for str2
    int k = 0;   // Index for result string

    /*
        Merge characters alternately from both strings
    */
    while (str1[i] != '\0' && str2[j] != '\0') {

        // Take one character from first string
        result[k++] = str1[i++];

        // Take one character from second string
        result[k++] = str2[j++];
    }

    /*
        If first string has remaining characters,
        append them to result
    */
    while (str1[i] != '\0') {
        result[k++] = str1[i++];
    }

    /*
        If second string has remaining characters,
        append them to result
    */
    while (str2[j] != '\0') {
        result[k++] = str2[j++];
    }

    // Null terminate the merged string
    result[k] = '\0';

    // Print the merged output
    printf("%s", result);

    return 0;   // End of program
}
