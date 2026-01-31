#include <Emp.h>

void Emp::setName(string _n) { strcpy(name,_n.c_str()); }

void Emp::setID(int _i) { id = _i; }

void Emp::display() { cout<<id<<"\t"<<name<<endl; }

void Emp::setEmp() 
{
	cout<<"Name: ";
	cin>>name;
	cout<<"ID: ";
	cin>>id;
}

bool Write2File(Emp& E)
{
	fstream fs;
	fs.open("Data.dat", ios::out | ios::app);
	if(!fs)
		return false;
	fs.write(reinterpret_cast<char*>(&E), sizeof(E));
	fs.close();

	return true;
}

bool ReadFFile( vector<Emp>&E_VC)
{
	fstream fs;
	Emp E;
	fs.open("Data.dat", ios::in);
	if(!fs)
		return false;
	while(!fs.eof())
	{
		memset(&E,0,sizeof(Emp));
		if(fs.read(reinterpret_cast<char*>(&E), sizeof(E)))
			E_VC.push_back(E);
	}
	fs.close();
	return true;
}