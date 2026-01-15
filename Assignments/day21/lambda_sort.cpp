#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <string>
 using namespace std;

 int main() {
 	vector<string> names = {"Souvik", "Rahul", "Anita", "Priya", "Karan"};

 	cout << "Before sorting:" << endl;
 	for (const auto& name : names)
     	cout << name << " ";
 	cout << endl;

 	sort(names.begin(), names.end(), [](const string& a, const string& b) {
     	return a > b; // Descending order
 	});

 	cout << "After sorting (Descending Order):" << endl;
 	for (const auto& name : names)
     	cout << name << " ";
 	cout << endl;

 	return 0;
 }