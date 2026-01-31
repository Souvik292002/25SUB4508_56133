/*
stack using Linked list
*/

#include <iostream>
#include <string>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int v) { this->data = v; next = nullptr;}
};

class Stack
{
private:
    Node *top;
public:
    Stack() : top(nullptr) {}

    void push(int v)
    {
        Node *nn = new Node(v);
        nn->next = top;
        top = nn;
    }

    void pop()
    {
        if(!top)
        {
            cout<<"\nStack is underflow"<<endl;
            return;
        }
        Node *temp = top;
        cout<<"\n"<<temp->data<<" Popped out"<<endl;
        top = top->next;
        delete temp;
    }

    void display()
    {
        Node *temp = top;
        while(temp != nullptr)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }

    ~Stack()
    {
        while(!top)
            pop();
    }
};


int main()
{

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();

    return 0;

}