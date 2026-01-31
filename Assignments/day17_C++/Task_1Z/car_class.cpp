 #include <iostream>
 #include <string>
 using namespace std;

 class Car {
 private:
 	string make;
 	string model;
 	int year;

 public:
 	void setMake(string m) {
     	make = m;
 	}

 	void setModel(string mo) {
     	model = mo;
 	}

 	void setYear(int y) {
     	year = y;
 	}

 	string getMake() {
     	return make;
 	}

 	string getModel() {
     	return model;
 	}

 	int getYear() {
     	return year;
 	}
 };

 int main() {
 	Car car1;

 	car1.setMake("Toyota");
 	car1.setModel("Corolla");
 	car1.setYear(2022);

 	cout << "Car Make: " << car1.getMake() << endl;
 	cout << "Car Model: " << car1.getModel() << endl;
 	cout << "Car Year: " << car1.getYear() << endl;

 	return 0;
 }
