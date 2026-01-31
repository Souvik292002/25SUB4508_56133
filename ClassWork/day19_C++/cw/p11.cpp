#include <iostream>

using namespace std;

class A 
{
    public:
        A(){cout<<"\nCnstr of A gets invoked\n";}
        virtual void disp() final { cout<<"disp of A called\n";}
};

class B: public A
{
    public:
        B(){cout<<"\nCnstr of B gets invoked\n";}
        void disp()  { cout<<"disp of B called\n";}
};

int main()
{
    B objB;
    objB.disp();
}