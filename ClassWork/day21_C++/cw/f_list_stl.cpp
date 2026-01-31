#include <iostream>
#include <forward_list>
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
    forward_list<Employee> empFList;

    empFList.push_front(Employee(501, "Arjun"));
    empFList.push_front(Employee(502, "Kavita"));
    empFList.push_front(Employee(503, "Rohit"));
    //empFList.push_back() (Employee(503, "Rohit"));

    cout << "Employees using std::forward_list:\n";
    for (const Employee &e : empFList)
    {
        e.display();
    }

    return 0;
}
