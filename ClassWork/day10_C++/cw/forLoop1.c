/*

for(initial sec; cond sec; counter)
{
    body of the loop
}

*/

#include <stdio.h>

int main()
{
    int table, counter;
    int prod;
    int j;
    //scanf("%d",&table);
    for(counter=1,table=9,j=10;(counter<11)&&(j>5);counter++,j--)
    {
        prod = table*counter;
        printf("\n%d X %d = %d \t j=%d",table,counter,prod,j);
    }

    printf("\n===========\n");

    return 0;
}