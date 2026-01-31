#include <iostream>

using namespace std;

int main()
{
    int a=10;
    int arr[] = {1,2,3,4,5};

    for(int i:arr)
    {
        cout<<"i= "<<i<<endl;
    }

    string name="bhima shankar";
    for(char i:name)
    {
        cout<<"i= "<<i<<endl;
    }

    for(auto i:name)
    {
        cout<<"i= "<<i<<endl;
    }




    cout<<"\n\n";
    return 0;
}