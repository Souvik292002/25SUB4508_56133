/*Q.3

C Program to Find the Frequency of Every Word in a given String

i/p
"Hi I am a C Programmer, I Love C Coding, I am Passionate towards C Coding"
o/p
I = 3
am = 2
C = 3
Coding = 2*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    // Input string (given sentence)
    char str[] = "Hi I am a C Programmer, I Love C Coding, I am Passionate towards C Coding";

    /*
        Remove punctuation marks like ',' and '.'
        by replacing them with space
    */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',' || str[i] == '.') {
            str[i] = ' ';
        }
    }

    char words[50][20];   // Array to store words
    int count[50] = {0}; // Frequency array
    int wordCount = 0;   // Number of words stored

    /*
        Break the string into words using strtok()
    */
    char *token = strtok(str, " ");

    while (token != NULL) {

        int found = 0;

        // Check if the word already exists
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        // If word not found, add it
        if (!found) {
            strcpy(words[wordCount], token);
            count[wordCount] = 1;
            wordCount++;
        }

        // Get next word
        token = strtok(NULL, " ");
    }

    /*
        Print words having frequency greater than 1
        (as per sample output)
    */
    for (int i = 0; i < wordCount; i++) {
        if (count[i] > 1) {
            printf("%s = %d\n", words[i], count[i]);
        }
    }

    return 0;   // End of program
}
