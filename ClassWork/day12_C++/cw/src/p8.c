/*
passing arrays to function
*/
#include <stdio.h>

void dispList(int [],int);


int main()
{
    int a[] = {10,3,5,6,8,0};
    int len = sizeof(a)/sizeof(a[0]);

    dispList(&a[0],len); //BA of the list/name of the array //pass by ref
    
    dispList(a,len);
    printf("\na[3] = %d",a[3]);
    return 0;
}

void dispList(int arr[], int len)
{
    for(int i=0;i<len;i++)
        printf("%d\t",arr[i]);
    
    arr[3] = 60;
    printf("\n");
}