#include <iostream>
#include "Stack.h"

using namespace std;

// Constructor
template <typename T>
Stack<T>::Stack(int s) {
    size = s;
    arr = new T[size];
    top = -1;
}

// Push function
template <typename T>
void Stack<T>::push(T value) {
    if (top == size - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top] = value;
}

// Pop function
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return T();
    }
    return arr[top--];
}

// isEmpty function
template <typename T>
bool Stack<T>::isEmpty() {
    return (top == -1);
}

// Destructor
template <typename T>
Stack<T>::~Stack() {
    delete[] arr;
}


template class Stack<int>;
template class Stack<double>;
