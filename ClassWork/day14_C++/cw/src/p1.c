#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 struct Employee
    {
        int empid;
        char empname[20];
    };


void disp(const struct Employee emp)
{
    static int Employee_No=1;

    printf("\nEmployee %d details\n", Employee_No);
    printf("\nName: %s", emp.empname);
    printf("\nID: %d",emp.empid);
    Employee_No++; 
}

int main()
{
   

    
    struct Employee emp1, emp2;


    scanf("%s%d",emp1.empname,&emp1.empid);
    scanf("%s%d",emp2.empname,&emp2.empid);


    printf("\nEmployee 1 details\n");
    printf("\nName: %s", emp1.empname);
    printf("\nID: %d",emp1.empid);

    printf("\nEmployee 2 details\n");
    printf("\nName: %s", emp2.empname);
    printf("\nID: %d",emp2.empid);

    disp(emp1); 
    disp(emp2);

    printf("\n\n");

    return 0;

}