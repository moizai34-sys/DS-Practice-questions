#include<iostream>
#include<string>
using namespace std;

class Stack
{
    int top;
    int capacity;
    int arr[11];

    public:

    Stack()
    {
        top = -1;
        capacity = 11;
    }

    void push(char val)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;

        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            
        }
        else
        {
            top--;
        }
        
    }

    char peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }
    bool check_palindrome(string str)
    {
        for(int i=0;i<str.length();i++)
        {
            push(str[i]);
        }

        for(int i=0;i<str.length();i++)
        {
            if (peek() != str[i])
            {
                pop();
                return false;
            }
            else
            {
                pop();
            }
        }
        return true;
    }




};

int main()
{
    Stack s;
    Stack s2;
    string str="BORROWORROB";

   
    if (s.check_palindrome(str))
    {
        cout<<"String is palindrome..."<<endl;

    }
    else
    {   
        
        cout<<"String is not palindrome..."<<endl;

    }

   

   
    
}

