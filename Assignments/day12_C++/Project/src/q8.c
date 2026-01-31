/*Given an array A of N positive numbers. The task is to find the position 
where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of   elements after it.

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
Output: 
3*/

#include <stdio.h>

int main()
{
    int n;
    int arr[100];
    int totalSum = 0, leftSum = 0;
    int i;

    /* Read size of the array */
    scanf("%d", &n);

    /* Read array elements */
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        totalSum += arr[i];   // Calculate total sum of array
    }

    /* Traverse array to find equilibrium index */
    for (i = 0; i < n; i++)
    {
        totalSum -= arr[i];   // Now totalSum becomes right sum

        /* Check if left sum equals right sum */
        if (leftSum == totalSum)
        {
            printf("%d\n", i);
            return 0;
        }

        /* Add current element to left sum */
        leftSum += arr[i];
    }

    /* If no equilibrium index found */
    printf("-1\n");

    return 0;
}
