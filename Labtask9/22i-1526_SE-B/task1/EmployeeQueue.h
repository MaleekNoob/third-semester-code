#include "EmployeeNode.h"

class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Non-parameterized constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Inserts the element at the rear of queue
    void enqueue(Node emp) {
        Node* newNode = new Node(emp);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->setNext(newNode);
            rear = newNode;
        }
    }

    // Removes the element from the front of queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            Node* temp = front;
            front = front->getNext();
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
        }
    }

    // Returns the value of the element at front of the queue
    Node showFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return Node();
        }
        else {
            return *front;
        }
    }

    // Returns True if queue is empty else returns False
    bool isEmpty() {
        return front == nullptr;
    }
};

