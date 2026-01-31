/*Check if two integers are multiples

Write a C program that reads two integers and checks whether they are multiplied or not.
Test Data :
Input the first number: 5
Input the second number: 15
Expected Output:
Multiplied!*/

#include <stdio.h>
int main() {
    int  x, y; // Declare variables for two integers

    // Prompt user for the first number and store in 'x'
    printf("\nInput the first number: "); 
    scanf("%d", &x);
    // Prompt user for the second number and store in 'y'
    printf("\nInput the second number: ");
    scanf("%d", &y);
  
    if(x > y) 
    {
        int temp;
        temp = x; // Swap the values of 'x' and 'y'
        x = y;
        y = temp;
    }
    
    if((y % x)== 0) // Check if 'x' is a factor of 'y'
    {
        printf("\nMultiplied!\n"); // Print message if 'x' is a factor of 'y'
    } 
    else 
    {
        printf("\nNot Multiplied!\n"); // Print message if 'x' is not a factor of 'y'
    }
    
    return 0;
}
