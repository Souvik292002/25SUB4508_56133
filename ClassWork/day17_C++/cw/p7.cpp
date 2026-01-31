#include <iostream>
#include <string>

using namespace std;


int main()
{
    int val = 10;
    int*ptr = &val;

    *ptr = 101;
    cout<<"val: "<<val<<endl;

    int &ref = val;
    cout<<"val: "<<ref<<endl;
    ref = 201;
    cout<<"val: "<<val<<endl;
    cout<<"Address of val: "<<&val<<endl;
    cout<<"ptr -> "<<ptr<<"\tref -> "<<&ref<<endl;


    return 0;
}