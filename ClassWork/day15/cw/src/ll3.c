#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next; //SRF
}NODE;


void dispList(NODE *);
NODE *createNode();
NODE *addBegin(NODE *, int);
NODE *addEnd(NODE *, int);
NODE *addAfterValue(NODE *, int, int);
NODE *deleteNode(NODE *, int);
void freeNodes(NODE *);


int main()
{
    NODE *head = NULL;
    int ch=1, value=0, after=0;
    while(ch)
    {
        printf("\n=============Linked List===============\n");
        printf("\nPress,");
        printf("\n1. Add node in the begining");
        printf("\n2. Add node in the end");
        printf("\n3. Add node after a value");
        printf("\n4. Delete Node");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nChoice: ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter the value of the Node: ");
                scanf("%d",&value);
                head = addBegin(head,value);
                break;
            case 2:
                printf("\nEnter the value of the Node: ");
                scanf("%d",&value);
                head = addEnd(head,value);
                break;
            case 3:
                printf("\nEnter the value of the Node to be searched: ");
                scanf("%d",&after);
                printf("\nEnter the value of the Node to be inserted: ");
                scanf("%d",&value);
                head = addAfterValue(head,after, value);
                break;
            case 4:
                printf("\nEnter the value of the Node to be deleted: ");
                scanf("%d",&value);
                head = deleteNode(head, value);
                break;
            case 5:
                dispList(head);
                break;
            case 6:
                freeNodes(head);
                exit(EXIT_SUCCESS);
            default:
                printf("\nEnter the correct choice");
            
        }


    }

    printf("\n\n");

    return (EXIT_SUCCESS);
}


NODE *createNode()
{
    return ((NODE *)malloc(sizeof(NODE)));
}

NODE *addEnd(NODE *head, int  val)
{
    NODE *nn = createNode();
    nn->val = val;
    nn->next = NULL;
    
    if(head == NULL)
    {
        //list is empty
        head = nn;
        
    }
    else
    {
        NODE *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = nn;
        
    }
    return head;
}

NODE *addBegin(NODE *head, int val)
{
    NODE *nn = createNode();
    nn->val = val;
    nn->next = head;
    return nn;
}


NODE *addAfterValue(NODE *head, int after, int val)
{
    NODE *temp = head;
    while(temp != NULL && temp->val != after)
        temp = temp->next;
    
    if(temp == NULL)
    {
        printf("\nvalue %d not found in the list",after);
        return head;
    }
    NODE *nn = createNode();
    nn->val = val;
  //  nn->next = NULL;
    nn->next = temp->next;
    temp->next = nn;
    return head;

}


NODE *deleteNode(NODE *head, int val)
{
    NODE *temp = head;
    NODE *prev = NULL;

    if(head == NULL)
    {
        printf("\nList is Empty\n");
        return head;
    }

    //first node to be deleted
    if(head->val == val)
    {
        head = head->next;
        free(temp);
        return head;
    }

    while(temp != NULL && temp->val != val)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("\n%d value not found in the list", val);
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
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

void freeNodes(NODE *head)
{
    NODE *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\nAll nodes are freed\n");
}