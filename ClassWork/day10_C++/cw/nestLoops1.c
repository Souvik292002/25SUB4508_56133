#include  <stdio.h>

int main()
{
    int table, counter;

    for(table=2;table<6;table++)
    {
        for(counter=1;counter<11;counter++)
            printf("\n%d x %d = %d",table, counter, (table*counter));
        
        printf("\n=================\n");
    }
    printf("\n==========================\n");

    return 0;

}