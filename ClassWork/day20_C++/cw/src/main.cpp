#include <LList.h>

int main()
{
    LList l;
    l.insertEnd(10);
    l.insertEnd(20);
    l.insertEnd(30);
    l.insertBegin(40);

    l.display();

    l.deleteVal(20);
    l.display();

    if(l.search(10)==false)
        cout<<"\nValue not found"<<endl;
    else
        cout<<"Value found in the list"<<endl;

    return 0;
    
}