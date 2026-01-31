#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Employee
{
public:
    int empId;
    string name;

    Employee(int id, string n) : empId(id), name(n) {}

    void display() const
    {
        cout << empId << " - " << name << endl;
    }

    // Required for sort and binary_search
    bool operator<(const Employee &e) const
    {
        return empId < e.empId;
    }

    // Required for find, equal, remove
    bool operator==(const Employee &e) const
    {
        return empId == e.empId;
    }
};

// Predicate for find_if
bool isSeniorEmployee(const Employee &e)
{
    return e.empId >= 103;
}

int main()
{
    vector<Employee> empVec = {
        Employee(101, "Ravi"),
        Employee(102, "Amit"),
        Employee(103, "Neha"),
        Employee(104, "Kiran")
    };

    cout << "Initial Employee List:\n";
    for (const auto &e : empVec)
        e.display();

    // --------------------------------------------------
    cout << "\n1. find():\n";
    auto it = find(empVec.begin(), empVec.end(), Employee(102, ""));
    if (it != empVec.end())
        it->display();

    // --------------------------------------------------
    cout << "\n2. find_if():\n";
    auto it2 = find_if(empVec.begin(), empVec.end(), isSeniorEmployee);
    if (it2 != empVec.end())
        it2->display();

    // --------------------------------------------------
    cout << "\n3. count():\n";
    int cnt = count(empVec.begin(), empVec.end(), Employee(101, ""));
    cout << "Employee ID 101 count = " << cnt << endl;

    // --------------------------------------------------
    cout << "\n4. equal():\n";
    vector<Employee> empVec2 = empVec;
    cout<<"\nSize of empvec: "<<empVec.size()<<"\nSize of empvec2: "<<empVec2.size()<<endl;
    empVec2.pop_back();
    cout<<"\nSize of empvec: "<<empVec.size()<<"\nSize of empvec2: "<<empVec2.size()<<endl;
    
    if (equal(empVec.begin(), empVec.end(), empVec2.begin()))
        cout << "Both employee lists are equal\n";

    // --------------------------------------------------
    cout << "\n5. search():\n";
    vector<Employee> pattern = {
        Employee(102, ""),
        Employee(103, "")
    };

    auto it3 = search(empVec.begin(), empVec.end(),
                      pattern.begin(), pattern.end());
    if (it3 != empVec.end())
        cout << "Pattern found starting at ID: " << it3->empId << endl;

    // --------------------------------------------------
    cout << "\n6. copy():\n";
    vector<Employee> copyVec;
    copy(empVec.begin(), empVec.end(), back_inserter(copyVec));
    for (const auto &e : copyVec)
        e.display();

    // --------------------------------------------------
    cout << "\n7. move():\n";
    vector<Employee> moveVec;
    move(empVec.begin(), empVec.end(), back_inserter(moveVec));
    cout << "After move, moved employees:\n";
    for (const auto &e : moveVec)
        e.display();

    // --------------------------------------------------
    cout << "\n8. remove():\n";
    empVec2.erase(remove(empVec2.begin(), empVec2.end(), Employee(102, "")),
                  empVec2.end());
    for (const auto &e : empVec2)
        e.display();

    // --------------------------------------------------
    cout << "\n9. swap():\n";
    swap(empVec2[0], empVec2[1]);
    for (const auto &e : empVec2)
        e.display();

    // --------------------------------------------------
    cout << "\n10. sort():\n";
    sort(empVec2.begin(), empVec2.end());
    for (const auto &e : empVec2)
        e.display();


    cout << "\n10. rsort():\n";
    sort(empVec2.rbegin(), empVec2.rend());
    for (const auto &e : empVec2)
        e.display();

    // --------------------------------------------------
    cout << "\n11. binary_search():\n";
    bool found = binary_search(empVec2.begin(), empVec2.end(), Employee(104, ""));
    cout << "Employee ID 104 found? " << (found ? "Yes" : "No") << endl;

    return 0;
}
