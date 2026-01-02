#include<stdio.h>
#include <stdlib.h>


int main()
{
    int *ptr = NULL;
    int a=101;
    //ptr = (int *)malloc(sizeof(int));
    ptr = &a;
    *ptr = 10;
    printf("\n%d",*ptr);


    //free(ptr);
    return 0;

}
    

