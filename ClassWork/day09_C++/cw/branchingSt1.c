/*

1. if
2. if else
3. else if ladder
4. switch
5. nested if sts

main block st
if(cond)
{
    //if block
}
else
{
    //else block
}

sts

*/

#include <stdio.h>

int main()
{
    int age;
    printf("\nenter your age to know voting eligibility: ");
    scanf("%d", &age);

    if(age >= 18)
    {
        printf("\nYour are eligible to vote\n");
    }
    else
    {
        printf("\nYou are not eligible to vote\n");
    }
    printf("\nEnd of the Program\n");

    return 0;
}