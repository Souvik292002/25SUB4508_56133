#include <iostream>
#include <string>

using namespace std;

//ABC
class Animal
{
    public:
        virtual void display() = 0;
        virtual void makesound() = 0; //pure virtual function
};

class Cat: public Animal
{
    public:
        void display() {cout<<"\nCat can walk and jump"<<endl;}
        void makesound() { cout<<"\nMeow\n"<<endl;}
};

class Dog: public Animal
{
    public:
        void display() {cout<<"\nDog can walk and jump"<<endl;}
        void makesound() { cout<<"\nBow\n"<<endl;}

};

int main()
{
    Animal *ptrBC;
    Cat c;
    Dog d;

    c.display();
    c.makesound();
    d.display();
    d.makesound();
    //Animal a;  // can't create obj of ABC
    ptrBC = &c;
    ptrBC->display();
    ptrBC->makesound();
    ptrBC = &d;
    ptrBC->display();
    ptrBC->makesound();
    
    return 0;
}