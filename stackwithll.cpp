#include<iostream>
using namespace std;    

class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Stack
{
    Node* top;
    int size;

    public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void push(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    int getSize()
    {
        return size;
    }
};