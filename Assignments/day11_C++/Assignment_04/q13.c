/*Reverse a given num
     i/p
	num 12345
     o/p
     num 54321*/

     #include <stdio.h>

int main() {

    int num;            // Variable to store the input number
    int reversed = 0;   // Variable to store reversed number

    // Read the input number
    scanf("%d", &num);

    /*
        Loop continues until all digits are processed
    */
    while (num > 0) {

        // Extract the last digit of num
        int digit = num % 10;

        // Append digit to reversed number
        reversed = reversed * 10 + digit;

        // Remove the last digit from num
        num = num / 10;
    }

    // Print the reversed number
    printf("%d", reversed);

    return 0;   // End of program
}
