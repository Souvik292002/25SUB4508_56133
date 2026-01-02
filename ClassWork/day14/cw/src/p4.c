#include <stdio.h>

typedef enum Weekdays
{
    MON,
    TUE,
    WED,
    THUR,
    FRI,
    SAT,
    SUN
}WD;

int main()
{
    //enum Weekdays day;
    WD day;
    printf("\nEnter the day (0-7): ");
    scanf("%d",&day);

    switch (day)
    {
        case MON:
            printf("\nThe Day is MONDAY");
            break;
        
        case TUE:
            printf("\nThe Day is TUESDAY");
            break;
        default:
            break;
    }
    printf("\n\n");

    return 0;
}