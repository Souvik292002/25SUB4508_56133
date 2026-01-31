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

    // Required for ordering in set
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
    set<Employee> empSet;

    empSet.insert(Employee(101, "Ravi"));
    empSet.insert(Employee(103, "Neha"));
    empSet.insert(Employee(102, "Amit"));
    empSet.insert(Employee(101, "Duplicate")); // Ignored

    cout << "Employees using std::set:\n";
    for (const Employee &e : empSet)
    {
        e.display();
    }

    return 0;
}
