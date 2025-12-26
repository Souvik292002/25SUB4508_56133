/*
Convert days to years, weeks, and days

Write a C program to convert specified days into years, weeks and days.
Note: Ignore leap year.

Test Data :
Number of days : 1329
Expected Output :
Years: 3
Weeks: 33
Days: 3
*/

#include <stdio.h>

int main()
{
    int days, years, weeks;

    days = 1329; // Total number of days

    // Converts days to years, weeks and days
    years = days/365; // Calculate years
    weeks = (days % 365)/7; // Calculate weeks
    days = days - ((years*365) + (weeks*7)); // Calculate remaining days

    // Print the results
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d \n", days);

    return 0;
}
