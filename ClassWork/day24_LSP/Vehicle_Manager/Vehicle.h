#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

/*
 * Base class: Vehicle
 * Defines a common interface for all vehicle types
 */
class Vehicle {
public:
    // Pure virtual function forcing derived classes
    // to implement their own mileage logic
    virtual double getMileage() const = 0;

    // Virtual destructor ensures proper cleanup
    virtual ~Vehicle();
};

/*
 * Derived class: Car
 */
class Car : public Vehicle {
private:
    double mileage;

public:
    explicit Car(double m);
    double getMileage() const override;
};

/*
 * Derived class: Bike
 */
class Bike : public Vehicle {
private:
    double mileage;

public:
    explicit Bike(double m);
    double getMileage() const override;
};

/*
 * Derived class: Truck
 */
class Truck : public Vehicle {
private:
    double mileage;

public:
    explicit Truck(double m);
    double getMileage() const override;
};

#endif // VEHICLE_H
