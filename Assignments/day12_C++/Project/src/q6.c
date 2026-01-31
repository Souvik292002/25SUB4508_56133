/*C Program to Find the Frequency of Characters in the given String*/

#include <stdio.h>

int main()
{
    char str[200];
    int freq[256] = {0};   // Frequency array for all ASCII characters
    int i;

    /* Read the input string including spaces */
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Count frequency of each character */
    for (i = 0; str[i] != '\0'; i++)
    {
        /* Ignore space character */
        if (str[i] != ' ' && str[i] != '\n')
        {
            freq[(int)str[i]]++;
        }
    }

    /* Display frequency of each character */
    printf("Character frequencies:\n");
    for (i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            printf("%c : %d\n", i, freq[i]);
        }
    }

    return 0;
}
