#include <iostream>
#include <queue>
using namespace std;

class Stack {
    private:
    queue<int> q1, q2;

    public:
    void push(int data) {
        while (!q1.empty()) {
            int val = q1.front();
            q2.push(val);
            q1.pop();
        }
        q1.push(data);
        while (!q2.empty()) {
            int value = q2.front();
            q1.push(value);
            q2.pop();
        }
    }

    void pop() {
        q1.pop();
    }

    int peek() {
        int val = q1.front();
        return val;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {

    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    cout << endl << stack.peek();
    stack.pop();
    cout << endl << stack.peek();
    stack.pop();
    cout << endl << stack.peek();
    stack.pop();
    stack.pop();
    if (stack.isEmpty()) {
        cout << endl << "Stack empty";
    }
    else {
        cout << endl << "Stack not empty";
    }

    return 0;
}