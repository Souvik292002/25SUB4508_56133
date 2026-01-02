#include <stdio.h>


int main()
{
    int a=10;
    int b=a++;
    int c=++b;

    a++;
    ++b;
    printf("\n %d %d %d\n",++a,b++,c++);


    return 0;
}