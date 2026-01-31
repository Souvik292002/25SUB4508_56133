/*
Write the logic to for incrementing Squared Number-Star Pattern.
Input Format      : Take N as input of type integer.
Output Format     : Print incrementing Squared Number-Star Pattern.

Constraints:
2<=N<=10
Sample Input:
5
Sample Output:
1*2*3*4*5
6*7*8*9*10
11*12*13*14*15
16*17*18*19*20
21*22*23*24*25
*/

#include <stdio.h>

int main() {

    int N;          // Number of rows and columns
    scanf("%d", &N);

    int num = 1;    // Variable to store incrementing numbers

    /*
        Outer loop controls the number of rows
    */
    for (int i = 1; i <= N; i++) {

        /*
            Inner loop controls the number of columns
        */
        for (int j = 1; j <= N; j++) {

            // Print the current number
            printf("%d", num);

            // Increment the number for next print
            num++;

            /*
                Print '*' only if it is not the last number in the row
            */
            if (j < N) {
                printf("*");
            }
        }

        // Move to next line after each row
        printf("\n");
    }

    return 0;   // End of program
}
