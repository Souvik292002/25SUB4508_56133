#include <stdio.h>

int main()
{

    
    int option;
CHOICE:
    printf("\nEnter the total weight of the cloths");
    printf("\nChoose: ");
    printf("\n1. 0-1kg");
    printf("\n2. 1-2kg");
    printf("\n3. 2-3kg");
    printf("\n4. 3-5kg");
    printf("\nChoice: ");
    scanf("%d",&option);
    
    //note: case values should be of int or single char const

    switch(option)
    {
        case 1:
                printf("\nEstimated Time to complete: 15 mins");
                break;
        case 2:
                printf("\nEstimated Time to complete: 30 mins");
                break;
        case 3:
                printf("\nEstimated Time to complete: 45 mins");
                break;
        case 4:
                printf("\nEstimated Time to complete: 60 mins");
                break;
        
        default:
                printf("\nIts either over weighted or Empty\n");
                goto END;
                break;

    }

    printf("\nWashing is Done!\n");
END:
    return 0;
}

/*
abort
yes
no

char ip[] ="yes"
if((strcmp(ip, "yes")==0) || (strcmp(ip, "Yes")==0) || (strcmp(ip,"YES")==0))
{
    printf();

}
else if((strcmp(ip, "no")==0) || (strcmp(ip, "No")==0) || (strcmp(ip,"NO")==0))
{
    printf();
    
}
else if((strcmp(ip, "abort")==0) || (strcmp(ip, "Abort")==0) || (strcmp(ip,"ABORT")==0))
{
    printf();
    
}

else{

}

*/