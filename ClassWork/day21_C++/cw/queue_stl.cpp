#include <iostream>
#include <queue>
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
    queue<Employee> empQueue;

    empQueue.push(Employee(201, "Kiran"));
    empQueue.push(Employee(202, "Suresh"));
    empQueue.push(Employee(203, "Meena"));

    cout << "Employees using std::queue (FIFO):\n";
    while (!empQueue.empty())
    {
        empQueue.front().display();
        empQueue.pop();
    }

    return 0;
}
