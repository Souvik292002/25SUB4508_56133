#include <stdio.h>

int main()
{
    int a=10;
    printf("\naddress of a = %u and its value is: %d",&a,a);

    printf("\nContents of a (using name) = %d",a);
    printf("\nContents of a (using address) = %u",*(&a)); //* -> dereferencing the pointer
    // Whenever you are dereferencing the ptrs => its will give you 
    // value stored at that address

    printf("\n\n");
    return 0;
}
