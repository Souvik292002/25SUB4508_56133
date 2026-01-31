#include <iostream>
#include <functional>
#include <string>

using namespace std;


void myFunc(function<void ()> f1)
{
    cout<<"Hello, ";
    f1();
    cout<<"\nBye"<<endl;
}

auto swapInts = [] (int &x, int &y) { int t = x; x=y; y=t;}; 
    

auto mysort = [](vector <int>&arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=0;j<arr.size()-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapInts(arr[j],arr[j+1]);
            }
        }
    }
};

/*int main()
{
    auto msg = []() { cout<<"\nHello World\n\n"<<endl;};

    msg();

    auto msg1 = []() { cout<<"Value : "<<10<<endl;};
    msg1();

    msg();

    auto add = [] (int x, int y) { return x+y;};

    cout<<add(2,3)<<endl;
    cout<<add(20,30)<<endl;

    
    int a=30, b=40;
    swapInts(a,b);
    cout<<a<<" "<<b<<endl;
    auto msg2 = []() { cout<<"Bhima"<<endl;};
    myFunc(msg2);

    return 0;

}
*/

int main()
{
    vector <int> v;
    v.push_back(10);
    v.push_back(5);
    v.push_back(11);
    v.push_back(2);
    v.push_back(1);
    v.push_back(7);

    mysort(v);

    for(int i: v)
    {
        cout<<"\n"<<i<<endl;
    }

    return 0;

}