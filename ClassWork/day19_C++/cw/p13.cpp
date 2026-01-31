/*
linked list using c++
Node - > Node 
Operation for linked list
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


class LList
{
private:
    Node *head;
public:
    LList()
    {
        head = nullptr;
    }

    void insertBegin(int v)
    {
        Node *nn = new Node(v);
        nn->next = head;
        head = nn;
    }

    void insertEnd(int v)
    {
        Node *nn = new Node(v);
        if(head == nullptr)
        {
            //empty list
            head = nn;
            return;
        }
        Node *temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = nn;
    }

    void deleteVal(int v)
    {
        if(head == nullptr)
        {
            cout<<"\nEmpty list\n";
            return;
        }
        if(head->data == v)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *curr = head;
        Node *prev = nullptr;
        while(curr != nullptr && curr->data != v)
        {
            prev = curr;
            curr = curr->next;
        }
        if(curr == nullptr)
        {
            cout<<v<<" Value not found"<<endl;
            return ;
        }
        prev->next = curr->next;
        delete curr;
    }

    bool search(int v)
    {
        Node *temp = head;
        while(temp != nullptr)
        {
            if (temp->data == v)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        if(head == nullptr)
        {
            cout<<"\nEmpty List\n";
            return;
        }
        Node *temp = head;
        while(temp != nullptr)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"nullptr\n";
    }

    ~LList()
    {
        Node *temp;
        while(head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main()
{
    LList l;
    l.insertEnd(10);
    l.insertEnd(20);
    l.insertEnd(30);
    l.insertBegin(40);

    l.display();

    l.deleteVal(20);
    l.display();

    if(l.search(10)==false)
        cout<<"\nValue not found"<<endl;
    else
        cout<<"Value found in the list"<<endl;

    return 0;
    
}