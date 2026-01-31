#include <iostream>
#include <unordered_map>
using namespace std;

class Employee
{
public:
    string name;

    Employee() {}
    Employee(string n)
    {
        name = n;
    }
};

int main()
{
    unordered_map<int, Employee> empUMap;

    empUMap[401] = Employee("Kiran");
    empUMap[402] = Employee("Meena");
    empUMap[403] = Employee("Suresh");

    cout << "Employees using std::unordered_map:\n";
    for (auto &e : empUMap)
    {
        cout << "ID: " << e.first << " Name: " << e.second.name << endl;
    }

    return 0;
}
