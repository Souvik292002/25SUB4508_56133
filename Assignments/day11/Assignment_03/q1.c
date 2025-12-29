/*1) write a program to read Sum and Product of digits in a given number

Input Format:
Read a positive integer N

Output Format:
Print the sum and product of digits of the number

Examples:
Input: N = 12
Output: 
sum =3 
product = 2.

Input: N = 1012
Output:
 Sum = 4 
product = 2*/

#include <stdio.h>

int main() {

    int N;              // Variable to store the input number
    int sum = 0;        // To store sum of digits
    int product = 1;    // To store product of digits (start with 1)

    // Read the input number
    scanf("%d", &N);

    /*
        Loop will run until all digits of N are processed
    */
    while (N > 0) {

        // Extract the last digit of N
        int digit = N % 10;

        // Add digit to sum
        sum = sum + digit;

        // Multiply digit with product
        product = product * digit;

        // Remove the last digit from N
        N = N / 10;
    }

    // Print the results in required format
    printf("sum = %d\n", sum);
    printf("product = %d", product);

    return 0;   // End of program
}
