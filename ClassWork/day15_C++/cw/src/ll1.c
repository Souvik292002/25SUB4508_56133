#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int v;
    int *ptr; //store address of its own type=> self refrencing pointers (SRP)
}NODE;

int main()
{
    //creating nodes
    NODE n1,n2,n3;
    NODE *tptr = NULL;
    //intialize values
    n1.v = 10;
    n1.ptr = NULL;

    n2.v = 20;
    n2.ptr = NULL;

    n3.v = 30;
    n3.ptr = NULL;

    //Make relationships/link the nodes

    n1.ptr = &n2;
    n2.ptr = &n3;


    printf("\nAddress of n1 = %u",&n1);
    printf("\nAddress of n2 = %u",&n2);
    printf("\nAddress of n3 = %u",&n3);

    printf("\nAddress of n1.ptr = %u",n1.ptr);
    printf("\nAddress of n2.ptr = %u",n2.ptr);
    printf("\nAddress of n3.ptr = %u",n3.ptr);


    //traversing in the linked list

    tptr = &n1;

    printf("\nn1.val =%d", tptr->v);
    //move tptr to next location i.e n2
    //tptr = &n2;
    //tptr = n1.ptr;
    tptr = tptr->ptr;

    printf("\nn2.val =%d", tptr->v);
    tptr = tptr->ptr;
    printf("\nn3.val =%d", tptr->v);
    tptr = tptr->ptr;
    if(tptr != NULL)
        printf("\nn4.val =%d", tptr->v);
    else
        printf("\nNULL\n");



    //traversing
    printf("\nList is \n");
    tptr = &n1;
    while(tptr != NULL)
    {
        printf("%d->", tptr->v);
        tptr = tptr->ptr;
        
    }
    printf("NULL\n");


    NODE n4;

    n4.v = 40;
    n4.ptr = NULL;

    n1.ptr = &n4;
    n4.ptr = &n2;

    printf("\nList is \n");
    tptr = &n1; //BA of the list
    while(tptr != NULL)
    {
        printf("%d->", tptr->v);
        tptr = tptr->ptr;
        
    }
    printf("NULL\n");

    NODE n5;

    n5.v = 50;
    n5.ptr = NULL;

    n3.ptr = &n5;
    
    printf("\nList is \n");
    tptr = &n1; //BA of the list
    while(tptr != NULL)
    {
        printf("%d->", tptr->v);
        tptr = tptr->ptr;
        
    }
    printf("NULL\n");

    NODE n6;

    n6.v = 60;
    n6.ptr = NULL;

    tptr = &n1;
    while(tptr->ptr != NULL)
        tptr = tptr->ptr;
    tptr->ptr = &n6;

    printf("\nList is \n");
    tptr = &n1; //BA of the list
    while(tptr != NULL)
    {
        printf("%d->", tptr->v);
        tptr = tptr->ptr;
        
    }
    printf("NULL\n");



    printf("\n\n");

    return 0;
    
    


}

