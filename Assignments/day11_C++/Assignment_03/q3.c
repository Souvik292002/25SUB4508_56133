/*3) Program to Check if product of digits of a number at even and odd places is equal.
Input: 

2841
Output:
 Yes

Input: 

4324
Output: 
No*/

#include <stdio.h>

int main() {

    int n;                  // Variable to store the input number
    scanf("%d", &n);        // Read input

    int oddProduct = 1;     // Product of digits at odd positions
    int evenProduct = 1;    // Product of digits at even positions
    int position = 1;       // Position counter (starts from 1)

    /*
        Loop runs until all digits are processed
    */
    while (n > 0) {

        // Extract the last digit
        int digit = n % 10;

        /*
            If position is odd, multiply with oddProduct
            Else multiply with evenProduct
        */
        if (position % 2 == 1) {
            oddProduct = oddProduct * digit;
        } else {
            evenProduct = evenProduct * digit;
        }

        // Remove last digit
        n = n / 10;

        // Move to next position
        position++;
    }

    /*
        Compare both products
    */
    if (oddProduct == evenProduct) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;   // End of program
}
