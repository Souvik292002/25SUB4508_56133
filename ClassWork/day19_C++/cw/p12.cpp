#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;


int main()
{
    ofstream o_fp;
    ifstream i_fp;
    char data[100];

    o_fp.open("test.txt", ios::out| ios::trunc);
    
    cin.getline(data,100);

    o_fp<<data<<endl;

    o_fp.close();

    memset(data,'\0',100);
    i_fp.open("test.txt", ios::in);
    //i_fp >> data;
    i_fp.getline(data,100);
    cout<<data<<endl;
    i_fp.close();

    return 0;

}