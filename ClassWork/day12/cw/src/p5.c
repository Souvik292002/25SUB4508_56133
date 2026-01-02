#include <stdio.h>

int main()
{
    int a[3] = {10,20,30};
    int *ptr;

    printf("\naddress of a[0] = %u and its value a[0]=%d",&a[0],a[0]);
    printf("\naddress of a[1] = %u and its value a[1]=%d",&a[1],a[1]);
    printf("\naddress of a[2] = %u and its value a[2]=%d",&a[2],a[2]);
    printf("\naddress of a[3] = %u and its value a[3]=%d",&a[3],a[3]);

    ptr = &a[0]; //BA of array

    printf("\n[using ptr] - a[0]=%u \t %u",ptr,*ptr);
    ptr++;
    printf("\n[using ptr] - a[1]=%u \t %u",ptr,*ptr);
    ptr++;
    printf("\n[using ptr] - a[2]=%u \t %u",ptr,*ptr);
    ptr++;
    printf("\n[using ptr] - a[3]=%u \t %u",ptr,*ptr);

    ptr = &a[0];

    for(int i=0;i<3;i++,ptr++){
        printf("\n[using ptr] - a[%d]=%u \t %u",i,ptr,*ptr);
        
    }

    printf("\n\n");
    return 0;
}