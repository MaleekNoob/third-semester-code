#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class List {
    private:
    public:
    Node* head;

    List() {
        head = NULL;
    }

    List(Node* head) {
        this->head = head;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void insertAtFront(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void Remove(int data) {
        Node* curr = head;
        Node* toDelete = NULL;
        while (curr->data != data) {
            toDelete = curr;
            curr = curr->next;
        }
        if (toDelete == NULL) {
            head = head->next;
            delete curr;
            return;
        }
        toDelete->next = curr->next;
        delete curr;        
    }

    bool isEmpty() {
        return head == NULL;
    }

    void print() {
        Node* curr = head;
        cout << endl << "Linked List data: ";
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    bool hasCycle() {
        if (head == NULL) {
            return false;
        }

        Node* tortoise = head;
        Node* hare = head;

        while (hare->next != NULL && hare->next->next != NULL) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    List list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    // list.insertAtEnd(3);
    // list.insertAtEnd(4);
    // list.insertAtEnd(5);

    // create a cycle
    Node* curr = list.head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = list.head;

    cout << "Has cycle: " << list.hasCycle() << endl;

    // remove cycle
    curr->next = NULL;

    cout << "Has cycle: " << list.hasCycle() << endl;

    return 0;
}

