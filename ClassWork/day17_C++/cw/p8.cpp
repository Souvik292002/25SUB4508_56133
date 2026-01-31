#include <iostream>
#include <string>

using namespace std;

int add(int x, int y)
{
    cout<<"f1"<<endl;
    return (x+y);
}

float add(float x, float y)
{
    cout<<"f2"<<endl;
    return (x+y);
}



int add(int x, int y, int z)
{
    cout<<"f3"<<endl;
    return (x+y+z);
}

int main()
{
    cout<<"Addition : "<<add(10,20)<<endl;
    float x=10.1, y=20;
    float ret = add(x,y);
    cout<<"Addition : "<<ret<<endl;
    cout<<"Addition : "<<add(10,20)<<endl;
    return 0;
}