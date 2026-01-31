#include <iostream>
#include <string>

using namespace std;

int main()
{
    int *ptr1 = new int[10];
    int *ptr2 = ptr1; //giving owner ship 

    delete [] ptr2;

}