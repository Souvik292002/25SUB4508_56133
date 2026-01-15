#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

int main() {
    auto a = 10;               // int
    auto b = 3.14;             // double
    auto c = 'X';              // char
    auto d = "Hello";          // const char*
    auto e = string("World");  // std::string

    cout << "Value of a: " << a << ", Type: " << typeid(a).name() << endl;
    cout << "Value of b: " << b << ", Type: " << typeid(b).name() << endl;
    cout << "Value of c: " << c << ", Type: " << typeid(c).name() << endl;
    cout << "Value of d: " << d << ", Type: " << typeid(d).name() << endl;
    cout << "Value of e: " << e << ", Type: " << typeid(e).name() << endl;

    return 0;
}
