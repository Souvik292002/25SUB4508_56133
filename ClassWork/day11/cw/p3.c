#include <stdio.h>

int main()
{
    char c='a';
    int a=10;
    float f=10.5;
    int arr[5] = {1,2,3,4,5};

    printf("\nAddress of c = %u and its value = %c",&c,c);
    printf("\nAddress of a = %u and its value = %d",&a,a);
    printf("\nAddress of f = %u and its value = %f",&f,f);

    printf("\n\n");
    
    for(int i=0;i<5;i++)
        printf("\nAddress of a[%d] = %u and its value = %d",i,&arr[i],arr[i]);
    
    printf("\n%d",arr[arr[1]]);



    printf("\n\n");
    return 0;
    
}