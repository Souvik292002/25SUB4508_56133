#include <iostream>
#include <string>

using namespace std;

class BC
{
public:
    BC(){ cout<<"\nBC Constr\n"<<endl;}
    ~BC(){ cout<<"\nBC Destr\n"<<endl;}
    void disp() { cout<<"\nBC display function got invoked\n"<<endl;}
};


class DC: public BC
{
public:
    DC(){ cout<<"\nDC Constr\n"<<endl;}
    ~DC(){ cout<<"\nDC Destr\n"<<endl;}
    void disp() { cout<<"\nDC display function got invoked\n"<<endl;} //oridden BC
};



int main()
{
    BC objBC;
    DC objDC;
    //objBC.disp();
    objDC.disp();
}