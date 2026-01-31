/*
late, run binding - polymorphism
*/

#include <iostream>
#include <string>

using namespace std;

class BC
{
protected:
    int val1;
public:
    BC(){ cout<<"\nBC Constr\n"<<endl;
        val1=101;
    }
    ~BC(){ cout<<"\nBC Destr\n"<<endl;}
    virtual void disp()
    { cout<<val1<<"\nBC display function got invoked\n"<<endl;
                  //cout<<"Val1 = "<<val1<<endl;
    }
};


class DC: public BC
{
public:
    DC(){ cout<<"\nDC Constr\n"<<endl;}
    ~DC(){ cout<<"\nDC Destr\n"<<endl;}
    void disp() { cout<<"\nDC display function got invoked \n"<<endl;} //oridden BC
    void show() { cout<<"DC show method got invoked"<<endl;}
};



int main()
{
    BC *ptrBC = nullptr;
    DC objDC; //4000
    ptrBC = &objDC;
    ptrBC->disp();
    
   
    
}

/*
4000 - objDC
BC properties -disp
DC properties val1, disp



*/