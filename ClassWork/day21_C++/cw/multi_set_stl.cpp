#include <iostream>
#include <set>
using namespace std;

class Employee
{
public:
    int empId;
    string name;

    Employee(int id, string n)
    {
        empId = id;
        name = n;
    }

    bool operator<(const Employee &e) const
    {
        return empId < e.empId;
    }

    void display() const
    {
        cout << empId << " - " << name << endl;
    }
};

int main()
{
    multiset<Employee> empMSet;

    empMSet.insert(Employee(204, "Anil4"));
    empMSet.insert(Employee(201, "Anil"));
    empMSet.insert(Employee(201, "Anil Duplicate"));
    empMSet.insert(Employee(202, "Sunita"));
    empMSet.insert(Employee(203, "Anil5"));

    cout << "Employees using std::multiset:\n";
    for (const Employee &e : empMSet)
    {
        e.display();
    }

    return 0;
}
