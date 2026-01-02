/*
Enumerated Data type;
1000 = Bhima
1001 = shankar

enum EXIT_STATUS
{
    EXIT_FAILURE=-1,
    EXIT_SUCCESS
    
};


f = -1
s = 0

enum WeekDays
{
    SUNDAY=1
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
    
}

*/

#include <stdio.h>

enum EXIT_STATUS
{
    EXIT_SUCCESS=0,
    EXIT_FAILURE=-1,
    EXIT_PENDING=1
};


int main()
{
    enum EXIT_STATUS status;
START:
    printf("\nPress,\n1. Pending\n0. Success\n-1. Failure\nChoic: ");
    scanf("%d",&status);


    
    switch(status)
    {
        case EXIT_SUCCESS:
            printf("\nYour program exited success\n");
            break;
        case EXIT_FAILURE:
            printf("\nYour Program exited abnormally\n");
            break;
        case EXIT_PENDING:
            printf("\nYour program is still running\n");
            break;
        
        default:
            printf("\nEnter the correct choice\n");
            goto START;

    }

    printf("\n\n");

    return 0;
}



