#include <iostream>
 using namespace std;

 int divide(int a, int b) {
 	if (b == 0)
     	throw b;
 	return a / b;
 }

 int main() {
 	int x, y;
 	cout << "Enter two integers: ";
 	cin >> x >> y;

 	try {
     	int result = divide(x, y);
     	cout << "Result = " << result << endl;
 	}
 	catch (int e) {
     	cout << "Error: Division by zero is not allowed." << endl;
 	}

 	return 0;
 }