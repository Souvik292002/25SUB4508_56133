/*Q.2
Given an array A of N positive numbers. The task is to find the position 
where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of   elements after it.

Input Format:
The first line contains an integer, denoting the size of the array. 
The second line contains integers denoting the elements 
of the array.
Constraints
1<= n<=100
1<=arr<= 1000, where arr is the ith element of the array.

Output Format:
The output line contains integer denoting an equilibrium
index (if any) or -1 (if no equilibrium indexes exist).

TESTCASE 1:
Input:
7
[-7, 1, 5, 2, -4, 3, 0]

o/p
3

I/p
5
[0 0 0 0 -1]

o/p
4*/

#include <stdio.h>

int main() {

    int n;                  // Size of the array
    scanf("%d", &n);

    int arr[n];             // Array declaration

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int totalSum = 0;       // Sum of all elements in array

    // Calculate total sum of array
    for (int i = 0; i < n; i++) {
        totalSum = totalSum + arr[i];
    }

    int leftSum = 0;        // Sum of elements to the left
    int found = 0;          // Flag to check equilibrium index

    /*
        Traverse the array to find equilibrium index
    */
    for (int i = 0; i < n; i++) {

        // Remove current element from totalSum
        // Now totalSum becomes right sum
        totalSum = totalSum - arr[i];

        // Check if left sum equals right sum
        if (leftSum == totalSum) {
            printf("%d", i);
            found = 1;
            break;          // First equilibrium index found
        }

        // Add current element to left sum
        leftSum = leftSum + arr[i];
    }

    // If no equilibrium index exists
    if (!found) {
        printf("-1");
    }

    return 0;               // End of program
}
