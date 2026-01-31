#include <iostream>

using namespace std;

class Emp
{
public:
    virtual ~Emp() {}
    virtual void info(){
        cout<<"\nEmployee base class"<<endl;
    }
};


class PerEmp: public Emp
{
public:
    void calculateSalary(){
        cout<<"\nPermanent Employee Salary calculted"<<endl;
    }
};


class ContEmp: public Emp
{
public:
    void calculateWages(){
        cout<<"\nContract Employee Wages calculted"<<endl;
    }
};

class UnknownEmp: public Emp
{
public:
    void calculateWages(){
        cout<<"\nUnknown Employee Wages calculted"<<endl;
    }
};


void ProcessEmp(Emp *emp)
{
    cout<<"\nActual Object type: "<<typeid(*emp).name()<<endl;

    if(typeid(*emp).name() == typeid(PerEmp).name())
    {
        cout<<"\nFirst object"<<endl;
        if(PerEmp *p = dynamic_cast<PerEmp*>(emp))
        {
            p->calculateSalary();
        }
    }
    else if(typeid(*emp).name() == typeid(ContEmp).name())
    {
        if( ContEmp *c = dynamic_cast<ContEmp*>(emp))
        {
            c->calculateWages();
        }   
    }
    
    else
    {
        cout<<"\nUnknown Employee type\n";
    }
}

int main()
{

    Emp *e1 = new PerEmp();
    Emp *e2 = new ContEmp();
    Emp *e3 = new UnknownEmp();
    ProcessEmp(e1);
    ProcessEmp(e2);
    ProcessEmp(e3);

    delete e1;
    delete e2;
    delete e3;
    return 0;
}