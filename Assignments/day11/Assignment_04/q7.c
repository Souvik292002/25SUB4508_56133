/*Find the GCD of the given list in such a way that by removing exactly one element and then taking the GCD will be the max

I/p
n= 3
7, 6 ,8

o/p
2

explanation: by removing 7 from the list GCD is 2 */

#include <stdio.h>

/*
    Function to calculate GCD of two numbers
    using Euclidean Algorithm
*/
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {

    int n;
    scanf("%d", &n);          // Read number of elements

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /*
        prefixGCD[i] stores GCD of elements from 0 to i
        suffixGCD[i] stores GCD of elements from i to n-1
    */
    int prefixGCD[n], suffixGCD[n];

    // Build prefix GCD array
    prefixGCD[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixGCD[i] = gcd(prefixGCD[i - 1], arr[i]);
    }

    // Build suffix GCD array
    suffixGCD[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixGCD[i] = gcd(suffixGCD[i + 1], arr[i]);
    }

    int maxGCD = 0;

    /*
        Try removing each element
    */
    for (int i = 0; i < n; i++) {

        int currentGCD;

        // If first element is removed
        if (i == 0) {
            currentGCD = suffixGCD[1];
        }
        // If last element is removed
        else if (i == n - 1) {
            currentGCD = prefixGCD[n - 2];
        }
        // Middle element removed
        else {
            currentGCD = gcd(prefixGCD[i - 1], suffixGCD[i + 1]);
        }

        // Update maximum GCD
        if (currentGCD > maxGCD) {
            maxGCD = currentGCD;
        }
    }

    // Print the result
    printf("%d", maxGCD);

    return 0;   // End of program
}
