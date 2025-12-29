/*C Program to Remove all Characters in Second String which are present in First String
i/p
S1 = Bhima S2 = shankar
o/p
snkr */

#include <stdio.h>

int main()
{
    char s1[100], s2[100];
    int i, j;
    int found;

    /* Read first string */
    printf("Enter first string (S1): ");
    scanf("%s", s1);

    /* Read second string */
    printf("Enter second string (S2): ");
    scanf("%s", s2);

    printf("Output: ");

    /* Traverse each character of second string */
    for (i = 0; s2[i] != '\0'; i++)
    {
        found = 0;

        /* Check if s2[i] exists in s1 */
        for (j = 0; s1[j] != '\0'; j++)
        {
            if (s2[i] == s1[j])
            {
                found = 1;   // Character found in first string
                break;
            }
        }

        /* If character is not found in first string, print it */
        if (found == 0)
        {
            printf("%c", s2[i]);
        }
    }

    printf("\n");
    return 0;
}
