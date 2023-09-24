// Algoirthm to convert infix expression to postfix expression
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;
};

template <class T>
class ListStack {
private:
    Node<T>* top;

public:
    ListStack() {
        top = NULL;
    }

    T __top__() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    void pop() {
        Node<T>* temp = top;
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        else {
            top = top->next;
            delete temp;
        }
    }

    void push(T value) {
        Node<T>* temp = new Node<T>;
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
        Node<T>* temp = top;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

bool prcd(char op1, char op2) {
    if (op1 == '(' || op2 == '(') {
        return false;
    }
    else if (op1 == '*' || op1 == '/') {
        if (op2 == '+' || op2 == '-') {
            return true;
        }
        else {
            return false;
        }
    }
    else if (op1 == '+' || op1 == '-') {
        if (op2 == '*' || op2 == '/') {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return true;
    }
}

bool IsOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string InfinixToPostfix(string infix) {
    ListStack<char> stack;
    string postfix = "";

    for (int i = 0 ; i < infix.length(); i++) {
        if (IsOperand(infix[i])) {
            postfix += infix[i];
        }
        else {
            while (!stack.isEmpty() && prcd(stack.__top__(), infix[i])) {
                postfix += stack.__top__();
                stack.pop();
            }
            if (infix[i] == ')') {
                while (stack.__top__() != '(') {
                    postfix += stack.__top__();
                    stack.pop();
                }
                stack.pop();
            }
            else {
                stack.push(infix[i]);
            }
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.__top__();
        stack.pop();
    }
    return postfix;
}

int main() {
    string infix, postfix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    postfix = InfinixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}