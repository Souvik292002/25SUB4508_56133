
 #include <iostream>
 #include <fstream>
 #include <string>
 using namespace std;

 // Function to write data to a file
 void writeToFile() {
 	ofstream outFile("sample.txt");

 	if (outFile.is_open()) {
     	outFile << "This is line 1 written to the file." << endl;
     	outFile << "This is line 2 written to the file." << endl;
     	outFile << "File I/O operations in C++ are simple." << endl;
     	outFile.close();
 	} else {
     	cout << "Error opening file for writing." << endl;
 	}
 }

 // Function to read data from a file
 void readFromFile() {
 	ifstream inFile("sample.txt");
 	string line;

 	if (inFile.is_open()) {
     	while (getline(inFile, line)) {
         	cout << line << endl;
     	}
     	inFile.close();
 	} else {
     	cout << "Error opening file for reading." << endl;
 	}
 }

 int main() {
 	writeToFile();

 	cout << "Reading contents from the file:" << endl;

 	readFromFile();

 	return 0;
 }