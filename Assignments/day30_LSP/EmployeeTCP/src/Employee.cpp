#include "Employee.h"
#include <iostream>
#include <stdexcept>

Employee::Employee(int id,
                   const std::string& n,
                   const std::string& p,
                   const std::string& d,
                   const std::string& a,
                   double s,
                   const std::string& u,
                   const std::string& pass)
    : empId(id), name(n), phone(p),
      designation(d), address(a),
      salary(s), username(u), password(pass)
{
    if (name.empty() || username.empty() || pass.empty())
        throw std::invalid_argument("Invalid employee data");
}

int Employee::getEmpId() const { return empId; }
std::string Employee::getUsername() const { return username; }
std::string Employee::getPassword() const { return password; }

void Employee::updateName(const std::string& n) {
    if (n.empty()) throw std::invalid_argument("Name cannot be empty");
    name = n;
}

void Employee::updatePhone(const std::string& p) {
    if (p.length() < 10) throw std::invalid_argument("Invalid phone number");
    phone = p;
}

void Employee::updateDesignation(const std::string& d) {
    designation = d;
}

void Employee::updateAddress(const std::string& a) {
    address = a;
}

// Friend function (admin read-only)
void viewEmployee(const Employee& e) {
    std::cout << "ID: " << e.empId
              << "\nName: " << e.name
              << "\nPhone: " << e.phone
              << "\nDesignation: " << e.designation
              << "\nAddress: " << e.address
              << "\nSalary: " << e.salary
              << "\n-------------------------\n";
}
