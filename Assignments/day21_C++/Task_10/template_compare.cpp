#include <iostream>
 #include <string>
 using namespace std;

 template <typename T>
 T compare(T a, T b) {
 	return (a > b) ? a : b;
 }

 int main() {
 	int i1 = 10, i2 = 20;
 	float f1 = 5.5, f2 = 2.3;
 	string s1 = "Apple", s2 = "Banana";

 	cout << "Larger integer: " << compare(i1, i2) << endl;
 	cout << "Larger float: " << compare(f1, f2) << endl;
 	cout << "Larger string: " << compare(s1, s2) << endl;

 	return 0;
 }