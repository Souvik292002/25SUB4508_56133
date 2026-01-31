#include <iostream>
#include <array>
using namespace std;

class Employee
{
    int empId;
    string name;

public:
    Employee() : empId(0), name("") {}

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
    array<Employee, 3> empArr = {
        Employee(101, "Amit"),
        Employee(102, "Ravi"),
        Employee(103, "Neha")
    };

    cout << "Employees using std::array:\n";
    for (int i = 0; i < empArr.size(); i++)
    {
        empArr[i].display();
    }

    return 0;
}
