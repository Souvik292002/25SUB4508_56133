/*Sum of Even and odd pos values in the array*/

#include <stdio.h>

int main() {

    int n;                         // Size of the array
    scanf("%d", &n);

    int arr[n];                    // Declare array of size n

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int evenPosSum = 0;            // Sum of elements at even positions
    int oddPosSum = 0;             // Sum of elements at odd positions

    /*
        Traverse the array
        Check position (index), not value
    */
    for (int i = 0; i < n; i++) {

        // If index is even
        if (i % 2 == 0) {
            evenPosSum = evenPosSum + arr[i];
        }
        // If index is odd
        else {
            oddPosSum = oddPosSum + arr[i];
        }
    }

    // Print the results
    printf("Sum of elements at even positions = %d\n", evenPosSum);
    printf("Sum of elements at odd positions = %d", oddPosSum);

    return 0;   // End of program
}
