#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    T peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return T();
        } else {
            return front->data;
        }
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
