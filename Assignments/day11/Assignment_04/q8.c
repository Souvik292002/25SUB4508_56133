/*Store Array from 1 to 100*/

#include <stdio.h>

int main() {

    int arr[100];    // Declare an integer array of size 100

    /*
        Store values from 1 to 100 in the array
        Index starts from 0, so:
        arr[0] = 1
        arr[1] = 2
        ...
        arr[99] = 100
    */
    for (int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }

    /*
        Print all elements of the array
    */
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }

    return 0;   // End of program
}
