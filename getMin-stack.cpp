#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
private:
    Node *top;
    Node *minTop; // additional stack to keep track of minimum values

public:
    Stack()
    {
        top = NULL;
        minTop = NULL;
    }

    Stack(Node *top)
    {
        this->top = top;
        minTop = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (top == NULL)
        {
            top = newNode;
            minTop = newNode; // initialize minimum value stack
        }
        else
        {
            newNode->next = top;
            top = newNode;
            if (newNode->data <= minTop->data)
            { // update minimum value stack
                Node *newMinNode = new Node(newNode->data);
                newMinNode->next = minTop;
                minTop = newMinNode;
            }
        }
    }

    void pop()
    {
        if (top != NULL)
        {
            Node *toDelete = top;
            top = top->next;
            if (toDelete->data == minTop->data)
            { // update minimum value stack
                Node *minToDelete = minTop;
                minTop = minTop->next;
                delete minToDelete;
            }
            delete toDelete;
        }
    }

    int Top()
    {
        if (top != NULL)
        {
            return top->data;
        }
        return -1;
    }

    int getMin()
    {
        if (minTop != NULL)
        {
            return minTop->data;
        }
        return -1;
    }

    ~Stack()
    {
        delete top;
        delete minTop;
    }
};

int main() {
    Stack* obj = new Stack();
    obj->push(-3);
    cout << endl << obj->getMin();
    obj->pop();
    cout << endl << obj->Top();
    cout << endl << obj->getMin();
    return 0;
}