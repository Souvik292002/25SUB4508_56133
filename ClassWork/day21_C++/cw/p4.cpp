#include <iostream>
#include <string>
#include <memory>

using namespace std;

void changeValue(int *ptr4)
{
    *ptr4 =  300;
}

unique_ptr<int> changeValueSptr(unique_ptr<int> ptr2)
{
    *ptr2 = 300;
    return (move(ptr2));
}

int main()
{
    unique_ptr<int> ptr1 = make_unique<int>(200);
    cout<<"value: "<<*ptr1<<endl;
    
    // unique_ptr<int> ptr2 = move(ptr1);
    //change ownsership from ptr1 to ptr2 in the function
    //then while returning back from the function change the
    //ownership from ptr2 back to ptr1
    ptr1 = changeValueSptr(move(ptr1)); 

    
    cout<<"value: "<<*ptr1<<endl;
    //cout<<"value: "<<*ptr1<<endl;


    int *ptr3 = new int(200);

    cout<<"value of ptr: "<<*ptr3<<endl;
    
    changeValue(ptr3);

    
    cout<<"value of ptr: "<<*ptr3<<endl;



    return 0;
    

}