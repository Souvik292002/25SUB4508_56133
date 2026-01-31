/*

+ => arthe
+ => char [] + char []

operator op ()
{
    body of the overloaded operation
}

operator +()
{
    task
}

*/

#include <iostream>
#include <string>

using namespace std;

class Number{
    int value;
    public:
        Number(int v=0){ value = v;}
        void display()
        {
            cout<<value<<endl;
        }
        Number operator + (Number other)
        {
            int val = value + other.value;
            Number nn(val);
            return nn;
        }
        Number operator - (Number other)
        {
            int val = value - other.value;
            Number nn(val);
            return nn;
        }

};

int main()
{
    Number n1(10),n2(20);
    Number n3 = n1 + n2;
    Number n4 = n2 - n1;

    n3.display();
    n4.display();
   // cout<<objEmp;
    return 0;
}

