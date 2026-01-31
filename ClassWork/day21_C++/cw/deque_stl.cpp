#include <iostream>
#include <deque>
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
    deque<Employee> empDeque;

    empDeque.push_back(Employee(301, "Anil"));
    empDeque.push_front(Employee(302, "Sunita"));
    empDeque.push_back(Employee(303, "Vijay"));

    cout << "Employees using std::deque:\n";
    for (auto it = empDeque.begin(); it != empDeque.end(); ++it)
    {
        it->display();
    }

    empDeque.pop_front();
    
    cout << "Employees using std::deque:\n";
    for (auto it = empDeque.begin(); it != empDeque.end(); ++it)
    {
        it->display();
    }
    return 0;
}
