#include <iostream>
#include <list>
using namespace std;

class Employee
{
    int empId;
    string name;

public:
    Employee(int id, string n)
    {
        empId = id;
        name = n;
    }

    void display() const
    {
        cout << "ID: " << empId << ", Name: " << name << endl;
    }
};

int main()
{
    list<Employee> empList;

    empList.push_back(Employee(401, "Ramesh"));
    empList.push_back(Employee(402, "Sita"));
    empList.push_front(Employee(403, "Mohan"));

    cout << "Employees using std::list:\n";
    for (const Employee &e : empList)
    {
        e.display();
    }

    // list<Employee>::iterator itr = empList.end();
    // while(itr != empList.begin())
    // {
    //     itr->display();
    //     itr--;
    // }


    return 0;
}
