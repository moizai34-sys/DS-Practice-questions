#include<iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int capacity;
    int arr[5];

    public:

    Queue()
    {
        front = -1;
        rear = -1;
        capacity = 5;
    }

    void enqueue(int val)
    {
        if ((rear + 1) % capacity == front)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
            front = 0;

        rear = (rear + 1) % capacity;
        arr[rear] = val;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == rear)
        {
            front = rear = -1; // Queue is now empty
        }
        else
        {
            front = (front + 1) % capacity;
        }
    }

    int peek()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }
};