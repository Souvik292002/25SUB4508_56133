/*
vhSeftCheck 
engineSpeed- rpm 
breakPressure - psi

>4000  and bp <30
unsafe

safe

*/
#include <iostream>

using namespace std;



//forward declaration of the class
class BrakeControlUnit; 

class EngineControlUnit
{
private:
    int engineRPM;
public:
    EngineControlUnit(int rpm){ engineRPM = rpm;}
    friend void SafetyCheckVechicle(const EngineControlUnit &, const BrakeControlUnit &);

};

class BrakeControlUnit
{
private:
    int breakPressure;
public:
    BrakeControlUnit(int pressure) { breakPressure = pressure;}
    friend void SafetyCheckVechicle(const EngineControlUnit &, const BrakeControlUnit &);

};


void SafetyCheckVechicle(const EngineControlUnit &ecu, const BrakeControlUnit &bcu )
{
    if((ecu.engineRPM > 4000)&&(bcu.breakPressure <30))
        cout<<"Status of Vechicle : Not Safe"<<endl;
    else
        cout<<"Status of Vechicle : Safe"<<endl;
}

int main()
{
    EngineControlUnit ecu(5000);
    BrakeControlUnit bcu(20);
    SafetyCheckVechicle(ecu,bcu);
}