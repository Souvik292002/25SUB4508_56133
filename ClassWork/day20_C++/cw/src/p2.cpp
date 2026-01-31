#include <iostream>
#include <string>

using namespace std;

class A //BC /Super class
{
    public:
        A(){ cout<<"\nCnstr of A invoked\n";}
        ~A(){ cout<<"\nDestr of A invoked\n";}
        void dispA(){ cout<<"\nDispA of A invoked\n";}
};


class B: virtual public A //DC /PC1
{
    public:
        B(){ cout<<"\nCnstr of B invoked\n";}
        ~B(){ cout<<"\nDestr of B invoked\n";}
        void dispB(){ cout<<"\nDispB of B invoked\n";}
};


class C: virtual public A //DC /PC2
{
    public:
        C(){ cout<<"\nCnstr of C invoked\n";}
        ~C(){ cout<<"\nDestr of C invoked\n";}
        void dispC(){ cout<<"\nDispC of C invoked\n";}
};

class D: public B, public C //class D is child of B and C
{
    public:
        D(){ cout<<"\nCnstr of D invoked\n";}
        ~D(){ cout<<"\nDestr of D invoked\n";}
        void dispD(){ cout<<"\nDispD of D invoked\n";}
};

int main()
{
    //B objB;
    //C objC;
    D objD;
    objD.dispA();
    cout<<endl;
    return 0;
}

