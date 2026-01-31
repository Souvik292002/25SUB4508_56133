#include <iostream>
#include <map>
using namespace std;

class Employee
{
public:
    string name;

    Employee(string n)
    {
        name = n;
    }

    void display() const
    {
        cout << name << endl;
    }
};

int main()
{
    multimap<int, Employee> empMMap;

    empMMap.insert({103, Employee("Ravi Contract3")});
    empMMap.insert({101, Employee("Ravi")});
    empMMap.insert({101, Employee("Ravi Contract")});
    empMMap.insert({102, Employee("Sunita")});

    cout << "Employees using std::multimap:\n";
    for (auto &e : empMMap)
    {
        cout << "ID: " << e.first << " | ";
        e.second.display();
    }

    return 0;
}
