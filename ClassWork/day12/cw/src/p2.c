#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qty=100;
    int price=201;

    int *ptr;

    ptr = &qty;

    printf("\nValue stored in qty (using ptr) = %d",*ptr);

    
    ptr = &price;

    printf("\nValue stored in price (using ptr) = %d",*ptr);

    *ptr = 300;

    printf("\nValue stored in price  = %d",price);

    printf("\n%u",ptr); // =>address of price
    printf("\n%u",&ptr); // =>address of ptr (its own address)
    


    printf("\n\n");

    return (EXIT_SUCCESS);
}