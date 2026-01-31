/*Check whether a given number can be expressed as the sum of two prime number

i/p
Enter a positive integer: 34
Output
34 = 3 + 31
34 = 5 + 29
34 = 11 + 23
34 = 17 + 17
NoofWays = 4

i/p 
Enter a positive integer: 1
Output
NoofWays: 0*/

#include <stdio.h>

/* Function to check whether a number is prime */
int isPrime(int num)
{
    int i;

    /* Numbers less than or equal to 1 are not prime */
    if (num <= 1)
        return 0;

    /* Check divisibility from 2 to num/2 */
    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return 0;   // Not prime
    }

    return 1;   // Prime number
}

int main()
{
    int n, i;
    int count = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    /* Loop from 2 to n/2 to avoid duplicate pairs */
    for (i = 2; i <= n / 2; i++)
    {
        /* Check if both numbers are prime */
        if (isPrime(i) && isPrime(n - i))
        {
            printf("%d = %d + %d\n", n, i, n - i);
            count++;
        }
    }

    /* Print number of ways */
    printf("NoofWays = %d\n", count);

    return 0;
}
