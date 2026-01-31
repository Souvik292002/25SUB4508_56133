#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

class Emp
{
private:
	int id;
	char name[20];
public:
	void setName(string); 
	void setID(int);
	void display();
	void setEmp();
};

bool Write2File(Emp&);
bool ReadFFile( vector<Emp>&);
