#include <iostream>

using namespace std;


class A
{
    public:
        A()
        {
            cout<<"\nCnstr of A\n"<<endl;
        }
};

class B
{
    public:
        B()
        {
            cout<<"\nCnstr of B\n"<<endl;
        }
};

class C : public B, public A
{
    public:
        C()
        {
            cout<<"\nCnstr of C\n"<<endl;
        }
};


int main()
{
    C objc;

}