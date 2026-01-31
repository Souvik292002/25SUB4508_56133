#include <iostream>
#include <string>
#include <memory>

using namespace std;


void changeValueSptr(shared_ptr<int> ptr)
{
    *ptr = 400;
    cout<<"[changeValueSptr]: Value: "<<*ptr<<endl;
    cout<<"Count of ptrs: "<<ptr.use_count()<<endl;
    
}


int main()
{
    shared_ptr<int> ptr1 = make_shared<int>(300);

    shared_ptr<int> ptr2;

    cout<<"Value of object: "<< *ptr1<<endl;
    cout<<"Count of ptrs: "<<ptr1.use_count()<<endl;
    ptr2 = ptr1;
    cout<<"Value of object: "<< *ptr2<<endl;
    cout<<"Count of ptrs: "<<ptr1.use_count()<<endl;
    cout<<"Count of ptrs: "<<ptr2.use_count()<<endl;
    
    changeValueSptr(ptr2);

    cout<<"Value of object: "<< *ptr2<<endl;
    cout<<"Count of ptrs: "<<ptr1.use_count()<<endl;
    
    
    return 0;
}