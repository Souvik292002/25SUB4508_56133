#include <iostream>
#include <string>

using namespace std;

class Emp
{
private:
    int id;
    float sal;
    string name;
public: 
    Emp(int id, float sal, string name)
    {
        this->id = id;
        this->sal = sal;
        this->name = name;
    }


    friend ostream& operator <<(ostream & out, const Emp &e )
    {
        out<<"\nName: "<<e.name<<"\nID: "<<e.id<<"\nSalary: "<<e.sal<<endl;
        return out;
    } 

};

int main()
{
    Emp e1(101,10000.5,"abcd1");

    cout<<e1;

    return 0;

}