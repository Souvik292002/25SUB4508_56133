/*
Single inheritence
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    int phno;
    char g;
    string name;
    string address;

protected:
    void disp_person()
    {
        cout<<"\n==========Personal details are==========\n";
        cout<<"\nName: "<<name<<endl;
        cout<<"\nGender: "<<g<<endl;
        cout<<"\nPhno: "<<phno<<endl;
        cout<<"\nAddress: "<<address<<endl;
        cout<<"\n=========================================\n";
    }
public:
    
    Person()
    {
        cout<<"Cnstr Person"<<endl;
    }
    Person(string n, char gen, string addr, int p)
    {
        name = n;
        g = gen;
        address = addr;
        phno = p;
    }
    
    ~Person()
    {
        cout<<"Destr Person"<<endl;
    }
};

class Employee: public Person
{
private:
    int e_id;
    float e_salary;
    string e_desg;
    string e_proj_id;
public:
    Employee()
    {
        cout<<"Cnstr Employee"<<endl;
    }
    Employee(int id,float sal, string d, string p_id, string n, 
        char gen, string addr, int p) : Person(n,gen,addr,p)
    {
        e_id = id;
        e_salary = sal;
        e_desg = d;
        e_proj_id = p_id;
    }

    void disp_emp()
    {
        disp_person();
        cout<<"\n==========Employee details are==========\n";
        cout<<"\nID: "<<e_id<<endl;
        cout<<"\nSalary: "<<e_salary<<endl;
        cout<<"\nDesignation: "<<e_desg<<endl;
        cout<<"\nProject ID: "<<e_proj_id<<endl;
        cout<<"\n=========================================\n";
    }
    ~Employee()
    {
        cout<<"Destr Employee"<<endl;
    }
};


int main()
{
    Employee e1(101, 20000, "SE", "P000101", "Spatarishi", 'M',"WB",8888);

    e1.disp_emp();

    return 0;
}