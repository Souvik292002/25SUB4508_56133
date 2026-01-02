/*

do {
    body of loop
}while(cond);

*/


#include <stdio.h>

int main()
{
    int table=7,counter;
    int prod;

    counter=11;
    do{
        prod = table * counter;
        printf("\n%d X %d = %d", table, counter, prod);
        counter++;
    }while(counter < 11);

    printf("\n================\n");

    return 0;

}