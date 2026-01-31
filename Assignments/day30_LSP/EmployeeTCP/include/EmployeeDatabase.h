#ifndef EMPLOYEEDATABASE_H
#define EMPLOYEEDATABASE_H

#include <vector>
#include <mutex>
#include <algorithm>
#include <stdexcept>
#include "Employee.h"

class EmployeeDatabase {
private:
    std::vector<Employee> employees;
    std::mutex dbMutex;
    int nextId;

public:
    EmployeeDatabase() : nextId(1001) {}

    int generateId() {
        std::lock_guard<std::mutex> lock(dbMutex);
        return nextId++;
    }

    void addEmployee(const Employee& e) {
        std::lock_guard<std::mutex> lock(dbMutex);
        employees.push_back(e);
    }

    Employee& authenticate(const std::string& user, const std::string& pass) {
        std::lock_guard<std::mutex> lock(dbMutex);
        for (auto& e : employees) {
            if (e.getUsername() == user && e.getPassword() == pass)
                return e;
        }
        throw std::runtime_error("Authentication failed");
    }

    void viewAllEmployees() {
        std::lock_guard<std::mutex> lock(dbMutex);
        std::sort(employees.begin(), employees.end(),
                  [](const Employee& a, const Employee& b) {
                      return a.getEmpId() < b.getEmpId();
                  });

        for (const auto& e : employees)
            viewEmployee(e);
    }
};

#endif
