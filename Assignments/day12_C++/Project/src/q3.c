/*C Program to Replace Lowercase Characters by Uppercase & Vice-Versa*/

#include <stdio.h>

int main()
{
    char str[100];
    int i;

    /* Read the input string including spaces */
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Traverse each character of the string */
    for (i = 0; str[i] != '\0'; i++)
    {
        /* Check for lowercase letters */
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            /* Convert lowercase to uppercase */
            str[i] = str[i] - 32;
        }
        /* Check for uppercase letters */
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            /* Convert uppercase to lowercase */
            str[i] = str[i] + 32;
        }
        /* Other characters remain unchanged */
    }

    /* Print the final string */
    printf("Modified string: %s", str);

    return 0;
}
