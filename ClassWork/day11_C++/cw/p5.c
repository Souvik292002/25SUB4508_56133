#include <stdio.h>
#define ROW 3
#define COL 2

/*

arr[6] = {1,2,3,4,5,6};
BA 
2000 = 1
2002 = 2
2004 = 3
2006 = 4
2008 = 5
2010 = 6

1       2       3       4       5       6
2000    2002    2004    2006    2008    2010


arr[3][2]

r=3,c=2

    c0  c1
r0  1   2
r1  3   4
r2  5   6

*/

int main()
{
    int arr[ROW][COL] = {1,2,3,4,5,6}; 
    int r,c;

    for(r=0;r<ROW;r++)
    {
        for(c=0;c<COL;c++)
            printf("\t%d ",arr[r][c]);
        printf("\n");
    }


     for(r=0;r<ROW;r++)
    {
        for(c=0;c<COL;c++)
            printf("\tAddress of arr[%d][%d] = %u and value %d ",r,c,&arr[r][c],arr[r][c]);
        printf("\n");
    }
    
    printf("\n\n");
    printf("\n\n");

    int *ptr = arr[0];
    for(int i;i<(ROW*COL);i++,ptr++)
        printf("\t%d ",*ptr);


    printf("\n\n");

    return 0;
}