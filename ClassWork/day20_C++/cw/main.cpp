#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

    // Integer Stack
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Integer Stack Output:" << endl;
    while (!intStack.isEmpty()) {
        cout << intStack.pop() << endl;
    }

    // Double Stack
    Stack<double> doubleStack(5);
    doubleStack.push(1.5);
    doubleStack.push(2.5);
    doubleStack.push(3.5);

    cout << "\nDouble Stack Output:" << endl;
    while (!doubleStack.isEmpty()) {
        cout << doubleStack.pop() << endl;
    }

    return 0;
}
