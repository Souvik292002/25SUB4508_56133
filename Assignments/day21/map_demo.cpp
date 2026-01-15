#include <iostream>
 #include <map>
 #include <string>
 using namespace std;

 int main() {
 	map<string, char> studentGrades;

 	studentGrades["Souvik"] = 'A';
 	studentGrades["Rahul"] = 'B';
 	studentGrades["Anita"] = 'A';
 	studentGrades["Priya"] = 'C';

 	cout << "Student Grades:" << endl;
 	for (const auto& entry : studentGrades) {
     	cout << entry.first << " -> " << entry.second << endl;
 	}

 	return 0;
 }