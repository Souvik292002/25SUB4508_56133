#include <iostream>
#include <memory>
using namespace std;

class Car {
public:
    Car(string name) {
        cout << "Car Constructor Called for " << name << endl;
        carName = name;
    }

    void display() {
        cout << "Car Name: " << carName << endl;
    }

    ~Car() {
        cout << "Car Destructor Called" << endl;
    }

private:
    string carName;
};

int main() {
    unique_ptr<Car> carPtr = make_unique<Car>("BMW");

    carPtr->display();

    return 0;
}
