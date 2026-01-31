/*
Single inheritence -> this pointer
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
    Person(string name, char g, string address, int phno)
    {
        this->name = name;
        this->g = g;
        this->address = address;
        this->phno = phno;
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
    Employee(int e_id,float e_salary, string e_desg, string e_proj_id, 
            string n, char gen, string addr, int p) 
            : Person(n,gen,addr,p)
    {
        this->e_id = e_id;
        this->e_salary = e_salary;
        this->e_desg = e_desg;
        this->e_proj_id = e_proj_id;
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