/*
Print employee ID and monthly salary

Write a C program that accepts an employee's ID, total worked hours in a month and the amount he received per hour. Print the ID and salary (with two decimal places) of the employee for a particular month.
Test Data :
Input the Employees ID(Max. 10 chars): 0342
Input the working hrs: 8
Salary amount/hr: 15000
Expected Output:
Employees ID = 0342
Salary = U$ 120000.00
*/

#include <stdio.h>
int main() {
    char id[11];         // Variable to store employee ID (up to 10 characters)
    int hour;            // Variable to store working hours
    double value, salary; // Variables for hourly salary and total salary

    // Prompt user for employee ID
    printf("Input the Employees ID(Max. 10 chars): ");
    scanf("%s", &id);

    // Prompt user for working hours
    printf("\nInput the working hrs: ");
    scanf("%d", &hour);

    // Prompt user for hourly salary
    printf("\nSalary amount/hr: ");
    scanf("%lf", &value);

    // Calculate total salary
    salary = value * hour;

    // Print employee ID and salary
    printf("\nEmployees ID = %s\nSalary = U$ %.2lf\n", id, salary);

    return 0;
}
