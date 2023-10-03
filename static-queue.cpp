// circular static queue
#include <iostream>
using namespace std;

const int capacity = 10;

class Node {
    int data;
    Node* next;
};

class Queue {
private:
    int arr[capacity], forward, rear, size;

public:
    Queue() {
        forward = -1;
        rear = -1;
        size = 0;
    }

    void Insert(int value);
    void Delete();
    bool isEmpty();
    bool isFull();
    void print();
};

void Queue::Insert(int value) {
    if (isFull()) {
        return;
    }
    else {
        forward++;
        forward = forward % capacity;
        arr[forward] = value;
    }
}

void Queue::Delete() {
    if (isEmpty()) {
        return;
    }
    else {
        rear++;
        rear = rear % capacity;
    }
}

bool Queue::isEmpty() {
    if (rear == -1 && forward == -1)
        return true;
    return false;
}

bool Queue::isFull() {
    if ((forward + 1) % capacity == rear % capacity)
        return true;
    return false;
}

void Queue::print() {
    for (int i = forward; i > rear; i--) {
        if (i == -1) {
            i = capacity - 1;
            continue;
        }
        cout << arr[i] << endl;
    }
}

int main() {

    Queue q;
    if (q.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty " << endl;
    
    q.Insert(10);
    q.Insert(20);
    q.Insert(30);
    q.Delete();
    q.Insert(40);
    q.Insert(50);
    q.Insert(60);
    q.Insert(70);
    q.Insert(80);
    q.Insert(90);
    q.Insert(100);
    q.Insert(110);
    q.print();

    if (q.isFull())
        cout << "Queue is full" << endl;
    else
        cout << "Queue is not full " << endl;

    return 0;
}