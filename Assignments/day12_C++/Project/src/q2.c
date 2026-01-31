/*C Program to Reverse every Word of given String

i/p
this is C Class
o/p
siht si C ssalC*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int start = 0, end, i;

    /* Read the input string (including spaces) */
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove newline character added by fgets */
    str[strcspn(str, "\n")] = '\0';

    /* Traverse the string */
    for (i = 0; i <= strlen(str); i++)
    {
        /* If space or end of string is found */
        if (str[i] == ' ' || str[i] == '\0')
        {
            end = i - 1;

            /* Reverse the current word */
            while (start < end)
            {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;

                start++;
                end--;
            }

            /* Move start to next word */
            start = i + 1;
        }
    }

    /* Print the final output */
    printf("%s\n", str);

    return 0;
}
