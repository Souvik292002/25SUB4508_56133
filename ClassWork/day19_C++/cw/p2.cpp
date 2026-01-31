#include <iostream>
#include <string>

using namespace std;

class Vechile{
    public:
        Vechile()
        {
            cout<<"\nThis is a Vechile"<<endl;
        }
};

class Car: public Vechile
{
    public:
       Car(){ cout << " The vechile is now called as car"<<endl;} 
};

class Bus: public Vechile
{
    public:
       Bus(){ cout << " The vechile is now called as Bus"<<endl;} 
};


int main()
{
    cout<<"\nHerarchile inheritence\n\n";
    Car objCar;
    Bus objBus;

    return 0;
}