#ifndef STACK_H
#define STACK_H

// Template class declaration
template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int size;

public:
    Stack(int s);      // Constructor
    void push(T value);
    T pop();
    bool isEmpty();
    ~Stack();
};

#endif
