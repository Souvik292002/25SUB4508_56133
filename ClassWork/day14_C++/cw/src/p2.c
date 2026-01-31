/*
Unions:

    1. union (keyword)
    2. only one member at a time can be accessed
    3. sizeof the union is the biggest/largest amoung the members
    
        Ex:
            union Employee{
                int empid;
                char empname[20];
            };


        Here the size of the union is 20 bytes (empname)

        union Employee e1;

        e1.empid = 1001;
        
        strcpy(e1.empname,"abc1");
        printf("\n%d",e1.empid);
        printf("\n%s",e1.empname);

        only empname is having data in the union
*/


#include <stdio.h>

union Employee
{
        int empid;
        float sal;
        char g;
        char empname[40];
        char empadd[100];
};


int main()
{

    union Employee emp1, emp2;

    printf("\nSizeof Employee: %d\n",sizeof(emp1));

    emp1.empid=1001;
    printf("\nID: %d",emp1.empid);
    strcpy(emp1.empname,"abc1");
    printf("\nName: %s",emp1.empname);


    printf("\n\n");

    return 0;

}