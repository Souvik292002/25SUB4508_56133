#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int data) { this->data = data; next = nullptr;}
};


class LList
{
private:
    Node *head;
public:
    LList() { head = nullptr; }

    void insertBegin(int );
    void insertEnd(int );
    void deleteVal(int);
    bool search(int);
    void display();

    ~LList();
};

/*
#ifndef LLIST_H
#define LLIST_H

#endif
*/