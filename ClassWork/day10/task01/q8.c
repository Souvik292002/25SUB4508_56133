/*Get month name from number (1–12)

Write a C program that reads an integer between 1 and 12 and prints the month of the year in English.
Test Data :
Input a number between 1 to 12 to get the month name: 8
Expected Output:
August*/

#include <stdio.h>
int main() {
    int mno; // Declare variable for month number

    // Prompt user for a number between 1 to 12
    printf("\nInput a number between 1 to 12 to get the month name: ");
    scanf("%d", &mno);

    switch(mno) {
        case 1 : printf("January\n"); break; // Print the name of the month for each case
        case 2 : printf("February\n"); break;
        case 3 : printf("March\n"); break;
        case 4 : printf("April\n"); break;
        case 5 : printf("May\n"); break;
        case 6 : printf("June\n"); break;
        case 7 : printf("July\n"); break;
        case 8 : printf("August\n"); break;
        case 9 : printf("September\n"); break;
        case 10 : printf("October\n"); break;
        case 11 : printf("November\n"); break;
        case 12 : printf("December\n"); break;
        default : printf("Input a number between 1 to 12."); // Print a message for an invalid input
    }
    
    return 0;
}
