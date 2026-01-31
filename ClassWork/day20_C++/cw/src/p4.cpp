#include <iostream>
#include <string>

using namespace std;

class A
{
    private:
        int a;
    public:
        A(){ cout<<"Cnstr of A"<<endl;}
        ~A(){ cout<<"Destr of A"<<endl;}
        void setA(int v){ this->a = v;}
        void dispA(){ cout<<"Value of a: "<<a<<endl;}
        friend int FriendvalueA(const A&);

};

int FriendvalueA(const A &objA)
{
    //objA.a = 100;
    return objA.a;
}

int main()
{
    A objA;
    objA.setA(10);
    objA.dispA();
    cout<<FriendvalueA(objA)<<endl;
    objA.dispA();
    return 0;
}