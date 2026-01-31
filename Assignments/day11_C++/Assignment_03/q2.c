/*2) Write a program to Count number of ways to divide a number
 in 4 parts.

 Input Format:
 First Line Of Input Contains T test cases
 Second line of Input Contains a positive integer n,

 Output Format:
 Print the count number of ways for divison can take place.

 Examples :

 Input:
 1
   5 => 1 + 1 + 1 + 2

 Output: 1

 Input:
 1
 6
   2 + 2 + 1 + 1
   1 + 1 + 1 + 3
 Output: 2

 Input:
 
   8
 Output: 5
1+1+1+5
2+2+2+2
2+2+1+3
1+1+2+4
3+3+1+1*/

#include <stdio.h>

int main() {

    int T;          // Number of test cases
    scanf("%d", &T);

    // Loop for each test case
    while (T--) {

        int n;      // Number to be divided into 4 parts
        scanf("%d", &n);

        int count = 0;   // To count valid divisions

        /*
            We try all possible values of a, b, c, d
            such that:
            a ≤ b ≤ c ≤ d
            a + b + c + d = n
        */

        for (int a = 1; a <= n; a++) {
            for (int b = a; b <= n; b++) {
                for (int c = b; c <= n; c++) {

                    // Calculate the fourth part
                    int d = n - (a + b + c);

                    /*
                        Conditions:
                        1. d must be >= c (to keep order)
                        2. d must be positive
                    */
                    if (d >= c && d > 0) {
                        count++;
                    }
                }
            }
        }

        // Print the count of ways
        printf("%d\n", count);
    }

    return 0;   // End of program
}
