#include <iostream>

using namespace std;

int main()
{
    int sum=0,a,b;
    cout<<"Enter the two values: ";
    cin>>a>>b;

    //int *ptr = (int *)malloc(sizeof(int)); 
    int *ptr = new (int);
    int *aptr = new int[5];

    //EMP *eptr = new (EMP);
    
    sum = a+b;
    *ptr = 10;
    cout<<*ptr<<endl;

    cout<<"Sum ="<<sum<<endl;
    delete [] aptr;

    delete ptr;

}