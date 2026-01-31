#include <iostream>
#include <unordered_set>
using namespace std;

class Employee
{
public:
    int empId;

    Employee(int id)
    {
        empId = id;
    }

    bool operator==(const Employee &e) const
    {
        return empId == e.empId;
    }
};

// Hash function
struct EmpHash
{
    size_t operator()(const Employee &e) const
    {
        return hash<int>()(e.empId);
    }
};

int main()
{
    unordered_set<Employee, EmpHash> empUSet;

    empUSet.insert(Employee(301));
    empUSet.insert(Employee(302));
    empUSet.insert(Employee(301)); // Ignored

    cout << "Employees using std::unordered_set:\n";
    for (const Employee &e : empUSet)
    {
        cout << "ID: " << e.empId << endl;
    }

    return 0;
}
