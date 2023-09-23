#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int* arr;
    int size;

public:
    Stack() {
        top = -1;
    }

    Stack(int length) {
        this->size = length;
        arr = new int[size];
        top = -1;
    }

    int __top__() {
        return top;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }

    void push(int value) {
        if (top == size - 1) {
            int* temp = new int[size * 2];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size *= 2;
        }
        top++;
        arr[top] = value;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void print() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    // Implementation of all functions of stack

    Stack s(5);
    s.isEmpty();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    s.pop();
    s.print();
    s.push(5);
    s.push(6);
    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.print();
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.push(12);
    s.print();
    cout << s.__top__() << endl;



    return 0;
}