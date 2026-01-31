/*
use case: washing m/c decides time consumed based on 
           weight of the cloths

           0-1kg -> 15 mins
           1-2kg -> 30 mins
           2-3kg -> 45 mins
           3-5kg -> 60 mins


*/

#include <stdio.h>

int main()
{
    int option;
    printf("\nEnter the total weight of the cloths");
    printf("\nChoose: ");
    printf("\n1. 0-1kg");
    printf("\n2. 1-2kg");
    printf("\n3. 2-3kg");
    printf("\n4. 3-5kg");
    printf("\nChoice: ");
    scanf("%d",&option);

    if(option == 1)
    {
        printf("\nEstimated Time to complete: 15 mins");
    }
    else if(option == 2)
    {
        printf("\nEstimated Time to complete: 30 mins");
    }
    else if(option == 3)
    {
        printf("\nEstimated Time to complete: 45 mins");
    }
    else if(option == 4)
    {
        printf("\nEstimated Time to complete: 60 mins");
    }
    else
        printf("\nIts either over weighted or Empty\n");

    printf("\nWashing is Done!\n");


    return 0;
    


}