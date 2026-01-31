

 #include <iostream>
 using namespace std;

 // Base class
 class Shape {
 public:
 	virtual void draw() {
     	cout << "Drawing a generic shape." << endl;
 	}
 };

 // Derived class Circle
 class Circle : public Shape {
 public:
 	void draw() override {
     	cout << "Drawing a Circle." << endl;
 	}
 };

 // Derived class Square
 class Square : public Shape {
 public:
 	void draw() override {
     	cout << "Drawing a Square." << endl;
 	}
 };

 int main() {
 	Shape* shape;

 	Circle c;
 	Square s;

 	shape = &c;
 	shape->draw();

 	shape = &s;
 	shape->draw();

 	return 0;
 }