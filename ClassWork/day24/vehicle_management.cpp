#include <iostream>
#include <vector>
using namespace std;

/*
 * Base class: Vehicle
 * Acts as a common interface for all vehicle types
 */
class Vehicle {
public:
    // Virtual function to be overridden by derived classes
    virtual double getMileage() const = 0;

    // Virtual destructor for proper cleanup via base pointer
    virtual ~Vehicle() {}
};

/*
 * Derived class: Car
 */
class Car : public Vehicle {
private:
    double mileage;

public:
    // Constructor to initialize mileage
    Car(double m) : mileage(m) {}

    // Override base class virtual function
    double getMileage() const override {
        return mileage;
    }
};

/*
 * Derived class: Bike
 */
class Bike : public Vehicle {
private:
    double mileage;

public:
    Bike(double m) : mileage(m) {}

    double getMileage() const override {
        return mileage;
    }
};

/*
 * Derived class: Truck
 */
class Truck : public Vehicle {
private:
    double mileage;

public:
    Truck(double m) : mileage(m) {}

    double getMileage() const override {
        return mileage;
    }
};

/*
 * Main function
 */
int main() {
    // STL vector holding base class pointers
    vector<Vehicle*> vehicles;

    // Adding different vehicle objects
    vehicles.push_back(new Car(15.5));
    vehicles.push_back(new Bike(45.0));
    vehicles.push_back(new Truck(8.2));

    // Display mileage using runtime polymorphism
    cout << "Vehicle Mileage Details:\n";
    for (const auto& vehicle : vehicles) {
        cout << "Mileage: " << vehicle->getMileage() << " km/l\n";
    }

    // Free allocated memory
    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}