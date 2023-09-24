#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class ListStack {
private:
    Node* top;

public:
    ListStack() {
        top = NULL;
    }

    int __top__() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    void pop() {
        Node* temp = top;
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        else {
            top = top->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* temp = new Node;
        temp->data = value;
        if (isEmpty()) {
            top = temp;
            top->next = NULL;
            return;
        }
        temp->next = top;
        top = temp;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void print() {
        Node* temp = top;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

int main() {
    ListStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.print();
    cout << endl;
    stack.pop();
    stack.print();
    cout << endl;
    cout << stack.__top__() << endl;
    return 0;
}