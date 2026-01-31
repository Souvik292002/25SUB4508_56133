#include <stdio.h>

int main()
{
    int a=10;
    int *ptr;
    printf("\naddress of a = %u and its value is: %d",&a,a);

    printf("\nContents of a (using name) = %d",a);
    printf("\nContents of a (using address) = %d",*(&a)); //* -> dereferencing the pointer
    // Whenever you are dereferencing the ptrs => its will give you 
    // value stored at that address

    ptr = &a; //ptr is storing 2000 (BA of a)

    printf("\nAddress of ptr = %u", &ptr);
    printf("\nSize of ptr %d",sizeof(ptr));
    printf("\nContentsof(%u)=%u",&a,a);
    printf("\nContentsof(%u)=%u",&ptr,ptr);
    printf("\nContentsof(contentsof(%u)) = %d",ptr,*ptr);
    
    *ptr = 22;
    printf("\nContentsof(contentsof(%u)) = %d",ptr,*ptr);
    printf("\naddress of a = %u and its value is: %d",&a,a);


    /*
    char *ptr1;
    printf("\nSize of ptr %d",sizeof(ptr1));
    */




    printf("\n\n");
    return 0;
}