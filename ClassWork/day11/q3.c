/*Write a C program to print alphabet triangle.
Input: 5
Output:

     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA
*/

#include <stdio.h>

int main() {

    int N;                  // Number of rows
    scanf("%d", &N);

    /*
        Outer loop controls number of rows
    */
    for (int i = 1; i <= N; i++) {

        /*
            Print leading spaces to center the pattern
        */
        for (int space = 1; space <= N - i; space++) {
            printf(" ");
        }

        /*
            Print increasing alphabets
            Example: A, AB, ABC ...
        */
        for (int ch = 0; ch < i; ch++) {
            printf("%c", 'A' + ch);
        }

        /*
            Print decreasing alphabets
            Example: BA, CBA, DCBA ...
        */
        for (int ch = i - 2; ch >= 0; ch--) {
            printf("%c", 'A' + ch);
        }

        // Move to next line after each row
        printf("\n");
    }

    return 0;   // End of program
}
