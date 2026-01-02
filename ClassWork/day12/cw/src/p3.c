#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20] = "Bhima";
    int *ptr;

    ptr = &name[0];

    printf("\n %c = %d", *ptr, *ptr);
    printf("\nBase Address of name = %u",&name[0]);
    printf("\nBase Address of ptr = %u", &ptr);
/*
    B = 1614701920
    h = 1614701921
    i = 1614701922
    m = 1614701923
    a = 1614701924
    \0 = 1614701925

*/
printf("\nBase Address of name = %u",&name[1]);

printf("\nName=%s\n",name);

printf("\nName=%s\n",ptr);

    printf("\n\n");

    return (EXIT_SUCCESS);
}