

 #include <iostream>
 #include <string>
 using namespace std;

 class Car {
 private:
 	string make;
 	string model;
 	int year;

 public:
 	// Constructor
 	Car(string m, string mo, int y) {
     	make = m;
     	model = mo;
     	year = y;
     	cout << "Car object created using constructor." << endl;
 	}

 	// Getter functions
 	string getMake() {
     	return make;
 	}

 	string getModel() {
     	return model;
 	}

 	int getYear() {
     	return year;
 	}

 	// Destructor
 	~Car() {
     	cout << "Car object destroyed using destructor." << endl;
 	}
 };

 int main() {
 	Car car1("Toyota", "Corolla", 2022);

 	cout << "Car Make: " << car1.getMake() << endl;
 	cout << "Car Model: " << car1.getModel() << endl;
 	cout << "Car Year: " << car1.getYear() << endl;

 	return 0;
 }