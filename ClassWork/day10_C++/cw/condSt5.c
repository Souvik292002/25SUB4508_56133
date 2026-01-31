#include <stdio.h>

int main()
{
    int prod,counter,table;
    counter=1;
    //table=2;
    scanf("%d",&table);
    
    while(counter < 11){
        prod = table * counter;
        printf("\n%d X %d = %d",table,counter, prod);
        counter++;
    }
    printf("\n===============\n");
    return 0;
}
