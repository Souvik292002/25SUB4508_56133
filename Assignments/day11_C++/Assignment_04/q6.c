/*Q6. Given an array of positive integers. 
Your task is to find the leaders in the array. An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader.

Input Format:
The first line contains an integer, denoting the size of the array. 
The second line contains integers denoting the elements of the array.
 
Constraints
 1<= n<=100-1000<=arr[i]<= 1000, where arr is the ith  element of the array.
 Output Format:
 The output line prints all the leaders in the array.
 
TESTCASE 1:
 Input:
 6
 6 7 4 3 5 2
 Output: 
 2 5 7
 
TESTCASE 2:
 Input:
 5
 2 6 3 8 4 
 Output:
 4 8*/

 #include <stdio.h>

int main() {

    int n;                  // Size of the array
    scanf("%d", &n);

    int arr[n];             // Array to store elements

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /*
        The rightmost element is always a leader
        So we start with it as the maximum
    */
    int maxFromRight = arr[n - 1];

    // Print the rightmost element (first leader)
    printf("%d ", maxFromRight);

    /*
        Traverse the array from right to left
    */
    for (int i = n - 2; i >= 0; i--) {

        // If current element is greater than max so far
        if (arr[i] > maxFromRight) {

            // Update maximum
            maxFromRight = arr[i];

            // Print the leader
            printf("%d ", maxFromRight);
        }
    }

    return 0;   // End of program
}
