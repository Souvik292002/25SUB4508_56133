#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template <class T> 
void swap_g(T &a, T &b)
{
    if(typeid(T) == typeid(int))
        cout<<"Type of T : "<<typeid(T).name()<<endl;
    
    
    T t;
    t=a;
    a=b;
    b=t;
}

//10+20.5 = 30.5
template <typename T1, typename T2>
auto add(T1 v1, T2 v2)
{
    return (v1+v2); 
}

int main()
{
    int a=10;
    int b=20;
    float x=20.5, y=30.6;
    string s1="abc1";
    string s2="xyz1";
    cout<<"Before Swap"<<endl;
    cout<<"swap (int,int)"<<a<<" "<<b<<endl;
    cout<<"swap (float,float)"<<x<<" "<<y<<endl;
    cout<<"swap (string,string)"<<s1<<" "<<s2<<endl;
    
    swap_g(a,b);
    swap_g(x,y);
    swap_g(s1,s2);
    cout<<"After Swap"<<endl;
    cout<<"swap (int,int)"<<a<<" "<<b<<endl;
    cout<<"swap (float,float)"<<x<<" "<<y<<endl;
    cout<<"swap (string,string)"<<s1<<" "<<s2<<endl;
    
    cout<<add(10,20.5)<<endl;
    cout<<add(20.5,10)<<endl;
    
    return 0;
}