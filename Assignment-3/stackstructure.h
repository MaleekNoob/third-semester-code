/*
Name : Maleek Hussain Ali
Roll No. : 22I-1526
Section : B
*/
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    Node<T>* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    T pop() {
        if (empty()) {
            std::cout << "Stack underflow" << std::endl;
            return T();
        }
        Node<T>* temp = top;
        T value = temp->data;
        top = top->next;
        delete temp;
        size--;
        return value;
    }

    T peek() const {
        if (empty()) {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return top->data;
    }

    bool empty() const {
        return top == nullptr;
    }

    int getSize() const {
        return size;
    }
};
