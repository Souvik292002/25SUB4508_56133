#include <stdio.h>


struct Book
{
        //member of the st
        char title[20];
        float price;
}b1,b2;

void disp(struct Book v);

void changeDetails(struct Book *);


int main()
{
    

    //struct Book b3,b4;

    //printf("\nSize of book = %d\n",sizeof(b4));

    /*
    
    access mem of st
    1 . (dot) operator => st variable is stack variable
    2. -> (arrow) operator => st variable is dy. type (pointer type)
    */

    struct Book b[3];

    strcpy(b1.title,"C Programming");
    b1.price = 101.4;

    scanf("%s%f",b2.title, &b2.price);
    
    printf("\nBook Details are\n");
    printf("\nBook1 - Title: %s",b1.title);
    printf("\nBook1 - Price: %f", b1.price);
    printf("\nBook2 - Title: %s",b2.title);
    printf("\nBook2 - Price: %f", b2.price);
    
    disp(b1);

    printf("\nBook Details are\n");
    printf("\nBook1 - Title: %s",b1.title);
    printf("\nBook1 - Price: %f", b1.price);


    changeDetails(&b1);

    printf("\nBook Details are\n");
    printf("\nBook1 - Title: %s",b1.title);
    printf("\nBook1 - Price: %f", b1.price);

    
    for(int i=0;i<3;i++)
        scanf("%s%f",b[i].title,&b[i].price);
    
    for(int i=0;i<3;i++)
        disp(b[i]);
    
    printf("\n\n");


    return 0;


    
}

void disp(const struct Book v)
{
    printf("\nBook Details are\n");
    printf("\nBook1 - Title: %s",v.title);
    printf("\nBook1 - Price: %f", v.price);
    //v.price = 555;
}

void changeDetails(struct Book *b)
{
    printf("\nBook Details are\n");
    printf("\nBook1 - Title: %s",b->title);
    printf("\nBook1 - Price: %f", b->price);
    b->price = 555;
}