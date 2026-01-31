#include <iostream>
#include <queue>
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
};

// Comparator for priority_queue
struct EmpCompare
{
    bool operator()(const Employee &e1, const Employee &e2)
    {
        return e1.empId < e2.empId;  // Higher ID = higher priority
    }
};

int main()
{
    priority_queue<Employee, vector<Employee>, EmpCompare> empPQ;

    empPQ.push(Employee(301, "Anil"));
    empPQ.push(Employee(305, "Sunita"));
    empPQ.push(Employee(302, "Vijay"));
    empPQ.push(Employee(308, "Vijay1"));
    empPQ.push(Employee(306, "Vijay2"));
    empPQ.push(Employee(300, "Vijay3"));



    cout << "Employees using std::priority_queue:\n";
    while (!empPQ.empty())
    {
        cout << "ID: " << empPQ.top().empId
             << ", Name: " << empPQ.top().name << endl;
        empPQ.pop();
    }

    return 0;
}
