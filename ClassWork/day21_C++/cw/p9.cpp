#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;


class Employee{
    int eid;
    string ename;
    float esal;
public:
    Employee() : eid(0), ename(""), esal(0.0){}
    Employee(int i, string n, float s): eid(i), ename(n), esal(s){}
    void setValue() {
        cout<<"\nEnter Name, id, sal of Employee\n"<<endl;

        cin>>ename>>eid>>esal;
    }
    void disp() { cout<<"\nName: "<<ename<<"\nID: "<<eid<<"\nSal: "<<esal<<endl;}

};

int main()
{
    vector <Employee> empv;
    Employee e;
    for(int i=0;i<3;i++)
    {
        e.setValue();
        empv.push_back(e);

    }
    
    for(auto e1:empv)
        e1.disp();

    cout<<"\n=================\n";
    vector<Employee>::iterator eitr = empv.begin();

    while(eitr != empv.end())
    {
        eitr->disp();
        eitr++;
    }
    
}
