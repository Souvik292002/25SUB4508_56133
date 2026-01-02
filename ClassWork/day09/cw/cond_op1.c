#include <stdio.h>

int func(int);

int main()
{
    int a=30, b=35,c=55;

    int res=0;

    res = (a>b)?((a>c)?(a):(c)):((b>c)?(b):(c));

    printf("\nResult = %d\n",res);

    sizeof(res++);
    
    printf("\nResult = %d\n",res);

    printf("\nResult [return from func] = %d\n", func(res++));
    printf("\nResult = %d\n",res);

    return 0;
}

int func(int val)
{
    printf("\nval [func] : %d\n", val);
    return val;
}