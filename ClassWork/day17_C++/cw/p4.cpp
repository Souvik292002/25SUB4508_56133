#include<iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    string myString = "hello123456789012345678901234567890 hello123456789012345678901234567890";
    myString ="abc";
    string myStr2 = "Abc";
    cout<<myString<<endl;
    cout<<"Capacity: "<<myString.capacity()<<endl;
    cout<<myString.compare(myStr2)<<endl;
    myString.clear();
    cout<<"mysring: "<<myString<<endl;
    cout<<"Capacity: "<<myString.capacity()<<endl;
    myString.append("bhima");
    cout<<"mysring: "<<myString<<endl;
    cout<<"length of the string "<<myString<<" is : "<<myString.length()<<endl;
    cout<<myString.at(1)<<endl;
    
    cout<<"Capacity: "<<myString.capacity()<<endl;
    //myString.erase();
    //cout<<"Capacity: "<<myString.capacity()<<endl;

    string mystr3 = myString + " " + myStr2;

    cout<<mystr3<<endl;
    myString.append(mystr3.append(" shankar"));

    cout<<myString<<endl;
    
    string mystr4;
    cin>>mystr4;
    cout<<mystr4<<endl;
    getchar();
    string mystr5;
    getline(cin, mystr5);
    cout<<mystr5<<endl;

    char name[50];
    strcpy(name,mystr5.c_str());
    cout<<"Name: "<<name<<endl;
    

    return 0;
}