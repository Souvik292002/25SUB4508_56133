#include <stdio.h>

int main()
{
    char msg[] = "Hello, World!";

    char *ptr = msg;
    int len = 0;

    while(*ptr != '\0')
    {
        putchar(*ptr);
        ptr++;
        len++;
    }

    printf("\nLength of the string = %d",len);
    printf("\n\n");
    return 0;

}