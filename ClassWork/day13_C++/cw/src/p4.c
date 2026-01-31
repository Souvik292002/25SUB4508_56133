#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int *ptr =(int *) calloc(5,sizeof(int));
    int *temp = ptr; //store BA of array

    ptr[0]=10;
    ptr[1]=20;
    ptr[2]=30;
    ptr[3]=40;
    ptr[4]=50;

    for(int i=0;i<5;i++)
        printf("\n%d",ptr[i]);

    for(int i=0;i<5;i++,ptr++)
        printf("\n%d",*ptr);
    
    ptr = temp;

    for(int i=0;i<5;i++,ptr++)
        printf("\n%d",*ptr);
    
    

    printf("\n\n");
    ptr = temp;

    free(ptr);
    

    return 0;
}