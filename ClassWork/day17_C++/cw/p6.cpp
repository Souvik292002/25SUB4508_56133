#include <iostream>

using namespace std;


typedef struct Employee
{
    int empid;
    int empage;
    string empname;

    bool checkVaildID()
    {
        cout<<"EMPID "<<empid<<endl;
        if (empid <0)
            return false;
        return true;
    }
}EMP;

int main()
{
    EMP e1;
    e1.empid = -100;
    e1.empage = 35;
    e1.empname = "abc1";

    if(e1.checkVaildID())
        cout<<"Valid ID"<<endl;
    else
        
        cout<<"ID is not valid"<<endl;
    
    return 0;
}
