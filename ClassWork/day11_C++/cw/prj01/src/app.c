#include <stdio.h>
#include <stdlib.h>
#include <calc.h>

int main()
{
    int val1,val2;
    printf("\nInput values of val1 and val2: ");
    scanf("%d%d",&val1,&val2);

    printf("Sum of %d + %d = %d\n",val1,val2,addition(val1,val2));
    printf("Negation of %d - %d = %d\n",val1,val2,substraction(val1,val2));
    
    return(EXIT_SUCCESS);
}


