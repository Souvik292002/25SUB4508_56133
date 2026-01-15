#include <iostream>
 using namespace std;

 // Abstract base class
 class Shape {
 public:
 	// Pure virtual function
 	virtual void draw() = 0;
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
 	Shape* shape1;
 	Shape* shape2;

 	Circle c;
 	Square s;

 	shape1 = &c;
 	shape2 = &s;

 	shape1->draw();
 	shape2->draw();

 	return 0;
 }
