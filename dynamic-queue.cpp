#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node() {
            next = NULL;
        }

        Node(int value) {
            data = value;
            next = NULL;
        }
};

class Queue {
    private:
        Node *forward, *rear;

    public:
        Queue() {
            forward = NULL;
            rear = NULL;
        }

        bool IsEmpty() {
            if (rear == NULL || forward == NULL)
                return true;
            return false;
        }
};

int main() {


    return 0;
}