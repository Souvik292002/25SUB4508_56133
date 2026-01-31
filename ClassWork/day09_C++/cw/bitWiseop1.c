#include <stdio.h>

int main()
{
    int a=5;
    unsigned long long int res = a >> 1;

    res = 3 ^ 2;

    /*
    left shift
    0000 0000 0000 0101
    0000 0000 0000 1010 = 10

    0000 0000 0000 0101
    0000 0000 0001 0100 = 20        
    

    right shift
    0000 0000 0000 0101
    0000 0000 0000 0010 = 2
    
    not op
    0000 0000 0000 0010 = 2
    1111 1111 1111 1101
    
    0000 0000 0000 0011 = 3
    0000 0000 0000 0010 = 2
    
    

    */

    printf("\n res = %lld\n", res);

    return 0;
}