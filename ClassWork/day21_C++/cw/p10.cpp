#include <iostream>
#include <typeinfo>
#include <exception>

using namespace std;

class BC{
public:
    virtual void show(){}
};


class DC : public BC
{
public:
    void special(){ cout<<"\nDerived specific function\n";}
};

int main()
{
    BC *b = new BC(); //2000 BC 4000 DC
    DC *d;
    try{
    d = dynamic_cast<DC *>(b); //downcasting(safe)
    }
    catch(bad_cast &e)
    {
        cout<<"Bad casting"<<e.what()<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"\n"<<typeid(*b).name()<<endl;
    cout<<"\n"<<typeid(b).name()<<endl;

    if(d != nullptr)
        d->special();
    else
        cout<<"Casting failed";

    delete b;

    return 0;

}

/*
RTTI is usefull when,
1. Object type is unknown at runtime
2. Objects come from frameworks
3. Base pointer refers to multiple dervied types


Real-world:
1. plugin systems
2. serialization 
3. Debugging 

filelogger(BC *ptr)
{
    if(typeid(ptr)==typeid(Admin))
    {
        dssldskm
    }
    else if (typeid(ptr)==typeid(Student))
    {
    }

}




*/

