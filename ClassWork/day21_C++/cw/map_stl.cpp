#include <iostream>
#include <map>
using namespace std;

class Employee
{
public:
    string name;
    float salary;

    Employee() {}
    Employee(string n, float s)
    {
        name = n;
        salary = s;
    }

    void display() const
    {
        cout << name << " - Salary: " << salary << endl;
    }
};

int main()
{
    map<int, Employee> empMap;

    empMap[101] = Employee("Ravi", 50000);
    empMap[102] = Employee("Neha", 55000);
    empMap[103] = Employee("Amit", 60000);
    empMap[102] = Employee("Kumar", 70000);
    
    cout << "Employees using std::map:\n";
    for (auto it = empMap.begin(); it != empMap.end(); ++it)
    {
        cout << "ID: " << it->first << " | ";
        it->second.display();
    }

    return 0;
}
