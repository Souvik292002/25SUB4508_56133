/*Sum of Even and odd values in the array*/

#include <stdio.h>

int main() {

    int n;                      // Size of the array
    scanf("%d", &n);

    int arr[n];                 // Declare array of size n

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int evenSum = 0;            // To store sum of even elements
    int oddSum = 0;             // To store sum of odd elements

    /*
        Traverse the array and classify elements
    */
    for (int i = 0; i < n; i++) {

        // Check if element is even
        if (arr[i] % 2 == 0) {
            evenSum = evenSum + arr[i];
        }
        // Otherwise, element is odd
        else {
            oddSum = oddSum + arr[i];
        }
    }

    // Print the results
    printf("Sum of Even numbers = %d\n", evenSum);
    printf("Sum of Odd numbers = %d", oddSum);

    return 0;   // End of program
}
