#include <stdio.h>

int main()
{
    int i;
    int n=20;

    for(i=1;i<=n;i++)
    {
        if(i!=n)
            printf("%d, ",(i*i)-1);
        else
            printf("%d ",(i*i)-1);
    }

    printf("\n\n");

    return 0;
}