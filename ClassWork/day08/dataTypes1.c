// representation of different data types
#include <stdio.h>

int main()
{
    unsigned char c;
    int i;
    float f;
    double d;

    printf("\nSize of char = %ld",sizeof(c));
    printf("\nSize of int = %ld",sizeof(i));
    printf("\nSize of float = %ld",sizeof(f));
    printf("\nSize of double = %ld",sizeof(d));
    
    c = 130;

    printf("\n %c = %d\n",c,c);

    long int li;
    printf("\nSize of long int = %ld\n",sizeof(li));
    short int si;
    printf("\nSize of short int = %ld\n",sizeof(si));
    

    return 0;

}

