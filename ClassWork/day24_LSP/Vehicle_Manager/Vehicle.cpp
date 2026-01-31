#include "Vehicle.h"

/*
 * Vehicle destructor definition
 */
Vehicle::~Vehicle() {
    // Empty destructor
}

/*
 * Car implementation
 */
Car::Car(double m) : mileage(m) {}

double Car::getMileage() const {
    return mileage;
}

/*
 * Bike implementation
 */
Bike::Bike(double m) : mileage(m) {}

double Bike::getMileage() const {
    return mileage;
}

/*
 * Truck implementation
 */
Truck::Truck(double m) : mileage(m) {}

double Truck::getMileage() const {
    return mileage;
}
