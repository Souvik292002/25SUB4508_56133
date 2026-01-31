#include <iostream>

using namespace std;

class A final
{
    public:
        A(){cout<<"\nCnstr of A gets invoked\n";}

};

class B: public A
{
    public:
        B(){cout<<"\nCnstr of B gets invoked\n";}

};

int main()
{
    B objB;
}