#include <iostream>

using namespace std;

class A
{
    int AccNo;
    public:
        static int AccountNo;
        A()
        {
            AccountNo++;
            AccNo = AccountNo;
        }
        void dispCount() { cout<<"Count of Objects: "<<AccountNo<<endl;}
        int getAccNo(){ return AccNo;}
};

//initial static members outside the class
int A::AccountNo = 10001;


int main()
{
    A a1,a2,a3;
    a1.dispCount();
    A a4;
    cout<<"Count of Objects: "<<A::AccountNo<<endl;
    a2.dispCount();
    cout<<a1.getAccNo()<<endl;
    cout<<a2.getAccNo()<<endl;
    cout<<a3.getAccNo()<<endl;
    cout<<a4.getAccNo()<<endl;



}