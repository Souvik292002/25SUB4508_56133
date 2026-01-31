#include <iostream>
#include <string>

using namespace std;



class Chair
{
protected:
   int legs;
   float price;
   float height;
   bool wheeled;
   bool handrest;
   string seat; //round/square
   string backrest; //fixed/recliner
   string matrial;
   string color;
   //by defaul all the members of the class are private to the class
public:
   void setLegs(int v) //setters
   {
        legs = v;
   }
   int getLegs() //getters
   {
        return legs;
   }
}; 

//class Employee; //Empty class => forward declaration

int main()
{
    Chair c1;
    cout<<"Size of e1: "<<sizeof(c1)<<endl;
    c1.setLegs(4);
    cout<<c1.getLegs()<<endl;
    return 0;
}