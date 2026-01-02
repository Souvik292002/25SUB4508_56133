#include <stdio.h>

int main()
{
    int a=10,b=20,c=5;

    if(a>b)
    {
        //if block
        if(a>c)
            printf("\na is the biggest\n");
        else
            printf("\nc is the biggest\n");
    }
    else
    {
        //else block
        if(b>c)
            printf("\nb is the biggest\n");
        else
            printf("\nc is the biggest\n");
    }

    printf("\nProgram End\n");

    return 0;
}