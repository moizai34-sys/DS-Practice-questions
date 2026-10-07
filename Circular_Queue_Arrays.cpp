#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;
    int size;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 5;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Insert element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Queue is full." << endl;
            return;
        }

        // First element
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        cout << value << " inserted into queue." << endl;
    }

    // Remove element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }

        cout << arr[front] << " removed from queue." << endl;

        // If only one element exists
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    // View front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {

    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    // Reusing empty spaces at beginning
    q.enqueue(60);
    q.enqueue(70);

    q.display();

    q.peek();

    return 0;
}
