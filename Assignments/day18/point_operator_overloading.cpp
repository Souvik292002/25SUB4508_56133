 #include <iostream>
 using namespace std;

 class Point {
 private:
 	int x;
 	int y;

 public:
 	// Constructor
 	Point(int xVal = 0, int yVal = 0) {
     	x = xVal;
     	y = yVal;
 	}

 	// Overload + operator
 	Point operator+(const Point& p) {
     	Point temp;
     	temp.x = x + p.x;
     	temp.y = y + p.y;
     	return temp;
 	}

 	// Display function
 	void display() {
     	cout << "Point(" << x << ", " << y << ")" << endl;
 	}
 };

 int main() {
 	Point p1(3, 4);
     Point p2(1, 2);

 	Point p3 = p1 + p2;

 	cout << "First Point: ";
 	p1.display();

 	cout << "Second Point: ";
 	p2.display();

 	cout << "Resultant Point after addition: ";
 	p3.display();

 	return 0;
 }
