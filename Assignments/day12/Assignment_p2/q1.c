/*Write a program to find the  n-th number made of prime digits 

Input Format:
First Line Of Input Contains T Number Of Test Cases
Second Line Of Input Contains an input Number N.

Output Format:
Print the Nth number of sequence and it should be only prime.

Constraints:
1<=T<=100
1<=N<=10000

Examples :
Input  : 
1
10
Output :
 33

2 3 5 7 22 23 25 27 32 33
       
Input  : 
1
21
Output :
 222*/

 #include <stdio.h>

int main()
{
    int T, N;
    int digits[] = {2, 3, 5, 7};   // Prime digits
    int result[20];               // To store generated number
    int index;

    /* Read number of test cases */
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &N);
        index = 0;

        /* Convert N into base-4 like representation */
        while (N > 0)
        {
            int rem = (N - 1) % 4;        // Adjust for no zero
            result[index++] = digits[rem];
            N = (N - 1) / 4;
        }

        /* Print the number in reverse order */
        for (int i = index - 1; i >= 0; i--)
        {
            printf("%d", result[i]);
        }

        printf("\n");
    }

    return 0;
}
