/*
malloc , calloc and realloc explaination
*/
#include <iostream>

int main()
{
    int *ptr = (int *)malloc(sizeof(int)*5);
    ptr[0]=10;
    ptr[1]=20;

    int *ptr1 = (int *)calloc(5, sizeof(int)); 2000-2020
    ptr1[0] = 10;
    ptr1[1] = 20;
    ptr1[2] = 30;

    2000 2004 2008......2020
     10    20  30 free()
    int *temp = (int *)realloc(ptr1, sizeof(int)*10); 40-> 3000-3043
    3000 3004 3008 3012 ... 3040
     10   20   30 
}