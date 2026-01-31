
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vechile
{
protected:
    string WheelType;
    string PowerType;
    string BreakType;
    string SteeringType;
    string MakeType;
    int noWheel;
    int noSeat;
    int speed;
};

class twoWeehler: public Vechile
{
    
protected:
    string ModeofAccl;

};

class cycle: public twoWeehler
{
protected:
    bool greaded;
    string cycleType;
};

class bike: public twoWeehler
{
protected:
    int noGears;
    string brand;
    string Model;
    string startType;
    int powerCC;
};

class Hero: public bike
{
private:
    string subModelType;
};

