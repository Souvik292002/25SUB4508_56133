#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    const int empId;              // immutable once created
    std::string name;
    std::string phone;
    std::string designation;
    std::string address;
    double salary;
    std::string username;
    std::string password;

public:
    Employee(int id,
             const std::string& n,
             const std::string& p,
             const std::string& d,
             const std::string& a,
             double s,
             const std::string& u,
             const std::string& pass);

    // getters
    int getEmpId() const;
    std::string getUsername() const;
    std::string getPassword() const;

    // employee-controlled updates
    void updateName(const std::string& n);
    void updatePhone(const std::string& p);
    void updateDesignation(const std::string& d);
    void updateAddress(const std::string& a);

    // admin-only read access
    friend void viewEmployee(const Employee& e);
};

#endif
