/*
//dec 
dt nameArr[CapofArr];

ex: 
    int arr[5];

    int arr1[5] = {1,2,3,4}; //dec with initialzation
    int arr2[] = {1,2,3,4};

    access the arry elem-> index op/value

    int a[3] = {1,2,3};
    printf("\na[2]=%d",a[2]); => o/p 3

    indexing starts from 0 to size-1

    3 types:
        1. 1-D => []
        2. 2-D => [][]
        3. multi-D => [][][]...
    
    4 types:
        1. static array : size of array are know beofore to compilation (@coding time)
            Ex: int a[10]; => size of the arry is 10 
        2. Dynamic array : Size of the array is known/allocated at run time
            Ex: int *ptr = (int *)malloc(sizeof(int)*3);
        3. Stretchable array: the size of the array can be incresed or dec at run (realloc)
        4. Mutable array: size of the array is known/alocated at link time
                extern

        
    
*/


#include <stdio.h>

int main()
{

    int arr[10];
    int i;
    printf("\nenter the values of arry\n");
    for(i=0;i<10;i++)
    {
        printf("\nEnter vallue of arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }

    printf("\nThe values of arry\n");
    for(i=0;i<10;i++)
    {
        printf("\narr[%d] =  %d",i, arr[i]);
        
    }
    printf("\n\n");
    return 0;

}
