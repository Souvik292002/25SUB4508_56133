#include <stdio.h>
#include <stdlib.h>

int main()
{

    char name[20] = "bhima";
    char *ptr;

    ptr = &name[0]; //pointing to BA of name

    printf("\nName: %s \n Name(using ptr): %s", name, ptr);
    printf("\nName: %s ", &name[0]);
    


    //ptr++;
    //printf("\nName: %s \n Name(using ptr): %c", name, *ptr);


    for(int i=0;i<5;i++,ptr++)
        printf("\n%c\n",*ptr);

    ptr = name;
    printf("\n%c = %d",*ptr, *ptr);


    

    printf("\n\n");

    return 0;
}