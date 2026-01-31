#include <LList.h>

void LList::insertBegin(int v)
    {
        Node *nn = new Node(v);
        nn->next = head;
        head = nn;
    }

void LList::insertEnd(int v)
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

void LList::deleteVal(int v)
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

bool LList::search(int v)
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

void LList::display()
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

LList::~LList()
    {
        Node *temp;
        while(head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }