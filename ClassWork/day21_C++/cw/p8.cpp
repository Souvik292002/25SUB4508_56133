#include <iostream>
#include <vector>
#include <iterator>


using namespace std;

int main()
{
    vector <int> v;

    cout<<"Size of the vector: "<<v.size()<<endl;
    cout<<"Capacity of Vector: "<<v.capacity()<<endl;

    v.push_back(10);
    cout<<"Size of the vector: "<<v.size()<<endl;
    cout<<"Capacity of Vector: "<<v.capacity()<<endl;

    v.push_back(20);
    cout<<"Size of the vector: "<<v.size()<<endl;
    cout<<"Capacity of Vector: "<<v.capacity()<<endl;

    v.push_back(30);
    cout<<"Size of the vector: "<<v.size()<<endl;
    cout<<"Capacity of Vector: "<<v.capacity()<<endl;

    v.push_back(40);
    cout<<"Size of the vector: "<<v.size()<<endl;
    cout<<"Capacity of Vector: "<<v.capacity()<<endl;


    v.push_back(50);
    cout<<"Size of the vector: "<<v.size()<<endl;
    cout<<"Capacity of Vector: "<<v.capacity()<<endl;


    for(auto items: v)
        cout<<items<<endl;

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    
    for(int i=0;i<v.size();i++)
        cout<<v.at(i)<<endl;

    cout<<"\nv[5]: "<<v[5]<<endl;
    //cout<<"\nv.at(5): "<<v.at(5)<<endl;
    /*
    terminate called after throwing an instance of 'std::out_of_range'

    */
    
   // v.insert()


   vector<int>::iterator itr = v.begin();

   while(itr != v.end())
   {
        cout<<*itr<<endl;
        itr++;
   }
    
}