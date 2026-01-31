/*4) Isha is playing with numbers and trying to write program to Check if the sum of distinct digits of two integers are equal

Output Format:
If  the sum of distinct digits of both the numbers are equal 
if true	print YES 
otherwise  print NO.

Examples:
Input: 
 2452
 9222
Output:
 YES

Input
121
3035
Output:
 NO*/



#include <stdio.h>

/*
    Function to calculate sum of distinct digits of a number
*/
int sumOfDistinctDigits(int n) {

    int visited[10] = {0};   // Array to track digits already counted
    int sum = 0;             // Sum of distinct digits

    /*
        Loop until all digits are processed
    */
    while (n > 0) {

        // Extract last digit
        int digit = n % 10;

        /*
            If digit is not visited, add to sum
            and mark it as visited
        */
        if (visited[digit] == 0) {
            sum = sum + digit;
            visited[digit] = 1;
        }

        // Remove last digit
        n = n / 10;
    }

    return sum;
}

int main() {

    int num1, num2;

    // Read the two input numbers
    scanf("%d", &num1);
    scanf("%d", &num2);

    // Calculate sum of distinct digits for both numbers
    int sum1 = sumOfDistinctDigits(num1);
    int sum2 = sumOfDistinctDigits(num2);

    /*
        Compare both sums
    */
    if (sum1 == sum2) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;   // End of program
}
