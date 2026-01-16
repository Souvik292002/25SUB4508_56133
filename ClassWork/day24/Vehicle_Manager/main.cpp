#include <iostream>
#include <vector>
#include "Vehicle.h"

using namespace std;

int main() {
    // STL vector storing base class pointers
    vector<Vehicle*> vehicles;

    // Adding vehicle objects
    vehicles.push_back(new Car(15.5));
    vehicles.push_back(new Bike(45.0));
    vehicles.push_back(new Truck(8.2));

    cout << "Vehicle Mileage Details:\n";

    // Runtime polymorphism in action
    for (const auto& vehicle : vehicles) {
        cout << "Mileage: " << vehicle->getMileage() << " km/l\n";
    }

    // Clean up dynamically allocated memory
    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
