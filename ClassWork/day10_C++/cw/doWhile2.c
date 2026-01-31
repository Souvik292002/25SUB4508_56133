/*
eat the food based on the taste of the food
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char option;
    int pEmpty = 10; //Plate Full = 10, empty = 0

    do{
        printf("\nTaking a bite from the plate");
        printf("\nWhether the food taste's good? (y/n): ");
        //fflush(stdin); flush/clear temp input buffer
        scanf("%c",&option);
        getchar();
        pEmpty--;
    }while((option == 'y') && (pEmpty!=0));

    if(pEmpty == 0)
        printf("\nYour Plate is Empty\n");
    else{
        printf("\nHope you didn't like the food\n");
        if (pEmpty / 2 > pEmpty)
            printf("\nSomething still is left on the plate");
        else
            printf("\nYour are wasting food\n");
    }
    printf("\n=======\n");

    return 0;
}