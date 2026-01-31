#include <iostream>
#include <stack>
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
    stack<Employee> empStack;

    empStack.push(Employee(101, "Ravi"));
    empStack.push(Employee(102, "Neha"));
    empStack.push(Employee(103, "Amit"));

    cout << "Employees using std::stack (LIFO):\n";
    while (!empStack.empty())
    {
        empStack.top().display();
        empStack.pop();
    }

    return 0;
}
