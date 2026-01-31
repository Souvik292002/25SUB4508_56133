#include <iostream>
#include <string>

using namespace std;


class Animal
{
    public:
        
        virtual void makesound(){cout<<"Animal makes a sound\n"<<endl;} 
};

class Cat: public Animal
{
    public:
        void display() {cout<<"\nCat can walk and jump"<<endl;}
        void makesound() override { cout<<"\nMeow\n"<<endl;}
};

class Dog: public Animal
{
    public:
        void display() {cout<<"\nDog can walk and jump"<<endl;}
        void makesound()  override { cout<<"\nBow\n"<<endl;}

};

int main()
{
    
    Cat c;
    Dog d;

    c.display();
    c.makesound();
    d.display();
    d.makesound();
    
    
    return 0;
}