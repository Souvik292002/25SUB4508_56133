#include <iostream>
 #include <vector>
 using namespace std;

 int findSum(const vector<int>& v) {
 	int sum = 0;
 	for (int num : v)
     	sum += num;
 	return sum;
 }

 double findAverage(const vector<int>& v) {
 	int sum = findSum(v);
 	return static_cast<double>(sum) / v.size();
 }

 int main() {
 	vector<int> numbers;

 	numbers.push_back(10);
 	numbers.push_back(20);
 	numbers.push_back(30);
 	numbers.push_back(40);
 	numbers.push_back(50);

 	cout << "Vector elements: ";
 	for (int n : numbers)
     	cout << n << " ";
 	cout << endl;

 	cout << "Sum = " << findSum(numbers) << endl;
 	cout << "Average = " << findAverage(numbers) << endl;

 	return 0;
 }

