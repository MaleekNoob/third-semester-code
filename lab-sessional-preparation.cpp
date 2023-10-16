#include <iostream>
using namespace std;

template <class T>
class Node {
    public:
    T data;
    Node* next;

    Node () {
        data = NULL;
        next = NULL;
    }

    Node (T data) {
        this->data = data;
        next = NULL;
    }
};

template <class T>
class Stack {
    private:
    Node<T>* top;

    public:
    Stack() {
        top = NULL;
    }

    Stack(Stack* stack) {
        top = stack;
    }

    void push(T data) {
        Node<T>* temp = new Node(data);

        if (isEmpty()) {
            top = temp;
        }
        else {
            temp->next = top;
            top = temp;
        }
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "ERor";
        }
        Node<T> *toPop = top;
        top = top->next;
        T var = toPop->data;
        delete toPop;
        return var;
    }

    Node<T>* Top() {
        return top;
    }

    T peek() {
        T var = top->data;
        return var;
    }

    int size() {
        Node<T> *traverse = top;
        int count = 0;
        while (traverse != NULL) {
            count++;
            traverse = traverse->next;
        }
        return count;
    }

    bool isEmpty() {
        if (top == NULL) {
            return true;
        }
        return false;
    }

    void print() {
        Node<T>* traverse = top;
        while (traverse != NULL) {
            cout << endl << traverse->data;
            traverse = traverse->next;
        }
    }
};

template <class T>
void generic_print(Stack<T>& stack) {
    if (!stack.isEmpty()) {
        cout << endl << stack.peek();
        T temp = stack.pop();
        generic_print(stack);
        stack.push(temp);
    }
}

template <class T2>
void insertAtEnd(Stack<T2>& stack, T2 value) {
    if (stack.isEmpty()) {
        stack.push(value);
        return;
    }
    T2 temp = stack.pop();
    insertAtEnd(stack, value);
    stack.push(temp);
}

template <class T1>
void reverse_stack(Stack<T1>& stack) {
    if (!stack.isEmpty()) {
        T1 temp = stack.pop();
        reverse_stack(stack);
        insertAtEnd(stack, temp);
    }
}

bool checkBrackets(string paraenthesis) {
    Stack<char> stack;
    for (int i = 0; i < paraenthesis.length(); i++) {
        char op = paraenthesis[i];

        if (op == '(' || op =='[' || op == '{') {
            stack.push(op);
        }
        else if (op == ')') {
            if (stack.pop() == '(')
                continue;
            else
                return false;
        }
        else if (op == ']') {
            if (stack.pop() == '[')
                continue;
            else 
                return false;
        }
        else if (op == '}') {
            if (stack.pop() == '{')
                continue;
            else    
                return false;
        }
        else 
            continue;
    }
    if (stack.isEmpty())
        return true;
    else 
        return false;
}

int main() {

    string paraenthesis;
    cout << "\nEnter string of paraenthesis: ";
    cin >> paraenthesis;
    if (checkBrackets(paraenthesis)) {
        cout << endl << "Balanced";
    }
    else {
        cout << endl << "Unbalanced";
    }
    return 0;
}