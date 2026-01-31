#include <stdio.h>

void func(int a)
{
    printf("\n[func]a=%d",a);
    a = 20;
    printf("\n[func]a=%d",a);
}


void funcByPtr(int *a)
{
    printf("\n[funcByPtr]a=%d",*a);
    *a = 20;
    printf("\n[funcByPtr]a=%d",*a);
}



int main()
{
    int val = 10;
    func(val); // pass by value
    printf("\nval=%d",val);
    printf("\n\n");

   
    funcByPtr(&val); // pass by pointer/ref

    printf("\nval=%d",val);
    printf("\n\n");

}