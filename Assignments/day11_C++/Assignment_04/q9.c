/*reverse the array.*/

#include <stdio.h>

int main() {

    int n;                  // Size of the array
    scanf("%d", &n);

    int arr[n];             // Declare array of size n

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int start = 0;          // Starting index
    int end = n - 1;        // Ending index

    /*
        Reverse the array by swapping elements
    */
    while (start < end) {

        // Swap arr[start] and arr[end]
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move pointers
        start++;
        end--;
    }

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;   // End of program
}
