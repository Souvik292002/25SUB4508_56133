/*
firend class
. not a derived class
. it can access all the mem of another
. used when one class must fully trust another class


class A
{
    friend class B;
}

*/


#include <iostream>
#include <string>

using namespace std;

//forward dec of friend class
class VechicleDig;

class EngineCtrlUnit
{
private:
    int engineRPM;
    int engineTemp;
public:
    EngineCtrlUnit(int rpm, int temp)
    {
        engineRPM = rpm;
        engineTemp = temp;
    }

    friend class VechicleDig;
};


class BrakeControlUnit
{
private:
    int breakPressure;
public:
    BrakeControlUnit(int pressure) { breakPressure = pressure;}
    friend class VechicleDig;
};


class VechicleDig
{
public:
    void runDigEngine(EngineCtrlUnit ecu)
    {
        cout<<"Engine RPM: "<<ecu.engineRPM<<endl;
        cout<<"Engine Temprature: "<<ecu.engineTemp<<endl;

        if(ecu.engineTemp > 110)
        {
            cout<<"\nFault: Engine Overheating"<<endl;
        }
        else
        {
            cout<<"\nStatus: Engine Temp is Normal"<<endl;
        }
    }

    void runDigBreak(BrakeControlUnit bcu)
    {
        cout<<"Break Pressure: "<<bcu.breakPressure<<endl;
        
        if(bcu.breakPressure < 30)
        {
            cout<<"\nFault: Check your break pressure"<<endl;
        }
        else
        {
            cout<<"\nStatus: Break Pressure is Normal"<<endl;
        }
    }
};


int main()
{
    EngineCtrlUnit ecu(1200,115);
    BrakeControlUnit bcu(20);
    VechicleDig diag;
    diag.runDigEngine(ecu);
    diag.runDigBreak(bcu);
    return 0;
}