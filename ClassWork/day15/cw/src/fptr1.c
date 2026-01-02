#include <stdio.h>

void f1()
{
    printf("\nbhima");
}

void f2()
{
    printf("\nSagnik");
}

void f3()
{
    printf("\nAdithya");
}

void testing(void (*f)())
{
    printf("\nHello");
    (*f)();
    printf("\nBye\n");
}

int main()
{
    f1();
    f2();
    f3();

    void (*fptr[3])();
    fptr[0] = f1;
    fptr[1] = f2;
    fptr[2] = f3;

    for(int i=0;i<3;i++)
    {
        testing(fptr[i]);
    }
    printf("\n\n");
}