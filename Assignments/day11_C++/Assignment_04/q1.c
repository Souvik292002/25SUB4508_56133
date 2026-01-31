/*Q1.
Problem Statement:
Given an unsorted array a of size N of non-negative integers, 
find a continuous sub-array which adds to a given number sum.

Input Format:
The first line contains an integer, denoting the size of the array. 
The second line contains integers denoting the elements 
of the array.
The last line contains an integer, denoting the sum. 

Constraints
1<= n<=100
1<=arr<= 1000, where arr is the ith element of the array.
1<= n<=100000

Output Format:
The output line contains integers denoting the indexes.

TESTCASE 1:
Input:
7
[1, 4, 0, 0, 3, 10, 5]

sum = 7
Output: 
Sum found between indexes 1 and 4

TESTCASE 2:
Input:
2
[1, 4]
sum = 0
Output: 
No subarray found*/

#include <stdio.h>

int main() {

    int n;          // Size of the array
    scanf("%d", &n);

    int arr[n];     // Array to store elements

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum;        // Target sum
    scanf("%d", &sum);

    int currSum = 0;    // Current window sum
    int start = 0;      // Starting index of window
    int found = 0;      // Flag to check if subarray is found

    /*
        Traverse the array using sliding window technique
    */
    for (int end = 0; end < n; end++) {

        // Add current element to current sum
        currSum = currSum + arr[end];

        /*
            If current sum becomes greater than target sum,
            remove elements from the left side
        */
        while (currSum > sum && start <= end) {
            currSum = currSum - arr[start];
            start++;
        }

        /*
            If current sum equals target sum,
            subarray is found
        */
        if (currSum == sum) {
            printf("Sum found between indexes %d and %d", start, end);
            found = 1;
            break;
        }
    }

    /*
        If no subarray is found
    */
    if (!found) {
        printf("No subarray found");
    }

    return 0;   // End of program
}
