#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int *ptr =(int *) malloc(5 * sizeof(int));
    int *temp = ptr; //store BA of array
    memset(ptr,0,5*sizeof(int));
    printf("\nBASE Address= %u",ptr);

    for(int i=0;i<5;i++,ptr++)
        scanf("%d",ptr);

    ptr = temp;

    for(int i=0;i<5;i++)
        printf("\n%d",ptr[i]);

    for(int i=0;i<5;i++,ptr++)
        printf("\n%d",*ptr);
    
    ptr = temp;

    for(int i=0;i<5;i++,ptr++)
        printf("\n%d",*ptr);
    
    printf("\nBASE Address= %u",ptr);

    printf("\n\n");
    ptr = temp;

    temp = realloc(ptr, 10*sizeof(int));
    printf("\nBASE Address[temp]= %u",temp);
    if(temp == NULL)
    {
        printf("\nUnable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    ptr = temp;
    for(int i=0;i<5;i++,ptr++);

    for(int i=0;i<5;i++,ptr++)
        scanf("%d",ptr);
   


    ptr = temp;

    for(int i=0;i<10;i++,ptr++)
        printf("\n%d",*ptr);


    ptr = temp;
    free(ptr);
    

    return 0;
}