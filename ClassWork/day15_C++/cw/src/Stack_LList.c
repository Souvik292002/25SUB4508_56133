/*
implement stack using liked list

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;


NODE *top = NULL;

void push(int val)
{
    NODE *nn = (NODE *)malloc(sizeof(NODE));
    nn->data = val;
    nn->next = top;
    top = nn;
}

void pop()
{
    if(top == NULL)
    {
        printf("\nStack is Empty\n");
        return;
    }
    NODE *temp = top;
    printf("\nPopped out Element = %d", temp->data);
    top = top->next;
    free(temp);
}

void dispStack()
{
    NODE *temp = top;

    if(temp == NULL)
    {
        printf("\nStack is Empty\n");
        return;
    }
    printf("\nStack Elements are\n");
    while(temp != NULL)
    {
        printf("\n%d",temp->data);
        temp = temp->next;
    }
}

int main()
{
    int ch,val;

    do{
        printf("\nPress,\n1. Push\n2. Pop\n3. Display\n0. Exit");
        printf("\nChoice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter value of element: ");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                dispStack();
                break;
            case 0:
                printf("\nThanks\n");
                break;
            default:
                printf("\nEnter the correct choice\n");
        }
        
    }while(ch !=0);

    printf("\n\n");
    return 0;
}