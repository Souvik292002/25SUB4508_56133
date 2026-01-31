/*
Single inheritence -> this pointer
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
   
    string name;
    

public:
    virtual void display()
    {
        cout<<"\n==========Personal details are==========\n";
        cout<<"\nName: "<<name<<endl;
        
        cout<<"\n=========================================\n";
    }
    virtual void setDetails(){}
public:
    
    Person()
    {
        cout<<"Cnstr Person"<<endl;
    }
    Person(string name)
    {
        cout<<"Para Cnstr Person"<<endl;
        this->name = name;
        
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
    
public:
    Employee()
    {
        cout<<"Cnstr Employee"<<endl;
    }
    Employee(int e_id, string n) 
            : Person(n)
    {
        cout<<"Para Cnstr Employee"<<endl;
        this->e_id = e_id;
        
    }
    
    void setValues(int id, string n)
    {
        this->e_id = id;
        name = n;
    }
    void setDetails()
    {
        cout<<"\nEnter,"<<endl;
        cout<<"\nName: ";
        cin>>name;
        cout<<"\nID: ";
        cin>>e_id;
    }
    void display()
    {
        
        cout<<"\n==========Employee details are==========\n";
        cout<<"\nID: "<<e_id<<endl;
        cout<<"\nName: "<<name<<endl;
        cout<<"\n=========================================\n";
    }
    ~Employee()
    {
        cout<<"Destr Employee"<<endl;
    }
};


int main()
{
    Person *ptrBC[3];

    
    for(int i=0;i<3;i++)
    {
        ptrBC[i] = new Employee();
    

        ptrBC[i]->setDetails();
    }


    ptrBC[0]->display();
    ptrBC[1]->display();
    ptrBC[2]->display();
    
    delete ptrBC[0];
    delete ptrBC[1];
    delete ptrBC[2];
    


    return 0;
}

/*
EMployee
[Person][Employee]
        
*/