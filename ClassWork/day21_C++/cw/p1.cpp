#include <iostream>
#include <string>
#include <exception>


using namespace std;


class MyException : public exception {
public:
   const char * what () const throw () {
      return "C++ Exception";
   }
};
 

double division(float nu, float  de)
{
    if (de == 0.0)
    {
        throw ("\nDivide by Zero Error\n");
    }

    return nu/de;
}


int main()
{
   
   try{
    float x=50.0, y=0.0;
    double z;
        throw MyException();
        int *n = new int[999999999999999];
        z = division(x,y);
        cout<<"z="<<z<<endl;
    }
    catch(MyException& e) {
      std::cout << "MyException caught" << std::endl;
      std::cout << e.what() << std::endl;
   } 
    catch(const char * e)
    {
        cerr<<e<<endl;
    }
    catch(exception &e)
    {
        cerr<<"Error: "<<e.what()<<endl;
    }
    
}