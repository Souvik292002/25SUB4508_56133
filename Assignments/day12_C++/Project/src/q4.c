/*C Program to Remove given Word from a String*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[200];
    char word[50];
    char result[200] = "";   // To store final string
    char temp[50];
    int i = 0, j = 0;

    /* Read the input string */
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove newline character */
    str[strcspn(str, "\n")] = '\0';

    /* Read the word to be removed */
    printf("Enter the word to remove: ");
    scanf("%s", word);

    /* Traverse the string */
    while (str[i] != '\0')
    {
        j = 0;

        /* Skip leading spaces */
        while (str[i] == ' ')
            i++;

        /* Extract a word from the string */
        while (str[i] != ' ' && str[i] != '\0')
        {
            temp[j++] = str[i++];
        }
        temp[j] = '\0';

        /* If extracted word is not equal to given word */
        if (strcmp(temp, word) != 0 && temp[0] != '\0')
        {
            strcat(result, temp);
            strcat(result, " ");
        }
    }

    /* Remove last extra space */
    if (strlen(result) > 0)
        result[strlen(result) - 1] = '\0';

    /* Print the final string */
    printf("Modified string: %s\n", result);

    return 0;
}
