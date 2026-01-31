#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next; //SRF
}NODE;


void dispList(NODE *);

int main()
{
    NODE *nn=NULL, *head = NULL, *temp=NULL;
    
    int value=0, ch=1;

    while(ch)
    {
        printf("\nEnter then value: ");
        scanf("%d",&value);

        //create nodes
        nn =(NODE *) malloc(sizeof(NODE));
        if(nn == NULL)
        {
            printf("\nUnbale to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        //assigning/initializing
        nn->val = value;
        nn->next = NULL;

        if(head == NULL)
        {
            //no list is present
            head = nn; //BA of the list
            temp = nn;
        }
        else
        {
            //the list is present/ one node atleast is present
            temp->next = nn;
            //100->next = 200
            temp = temp->next;
            //temp = 200
        }


        printf("\nDo you want to add new node (1/0): ");
        scanf("%d",&ch);
    }


    dispList(head);

    printf("\n\n");

    return (EXIT_SUCCESS);
}


void dispList(NODE *temp)
{
    printf("\nList is\n");
    while(temp != NULL)
    {
        printf("%d->",temp->val);
        temp = temp->next;
    }
    printf("NULL\n\n");
}