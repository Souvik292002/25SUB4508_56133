#include <iostream>
#include <vector>
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
    vector<Employee> empVec;

    empVec.push_back(Employee(201, "Kiran"));
    empVec.push_back(Employee(202, "Suresh"));
    empVec.push_back(Employee(203, "Meena"));
    empVec.emplace_back(Employee(204,"Shubham"));
    

    cout << "Employees using std::vector:\n";
    for (size_t i = 0; i < empVec.size(); i++)
    {
        empVec[i].display();
    }

    return 0;
}
