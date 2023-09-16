#include <iostream>
using namespace std;

// template <class T>
class Node {
public:
    int data;
    Node *next;
};

class List {
private:
    Node* head;
    int size;

public:
    List() {
        head = NULL;
        size = 0;
    }

    ~List() {
        delete head;
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    bool IsEmpty() {
        if (size = 0)
            return true;
        return false;
    }

    void InsertAtFront(int x) {
        Node *ptr = new Node;
        ptr->data = x;
        ptr->next = head;
        head = ptr;
        size++;
    }

    void InsertAtLast(int x) {
        Node *ptr = new Node;
        ptr->data = x;
        ptr->next = NULL;

        if (head == NULL) {
            head = ptr;
            size++;
        }
        else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }

            current->next = ptr;
            size++
        }
    }

    void InsertNode(int x, int p)
    {
        if (p >= 0 && p <= size)
        {
            Node *ptr = new Node;
            ptr->data = x;

            if (p == 0)
            {
                ptr->next = head;
                head = ptr;
            }
            else
            {
                Node *previous = head;

                for (int i = 0; i < p - 1; i++)
                {
                    previous = previous->next;
                }

                ptr->next = previous->next;
                previous->next = ptr;
            }

            size++;
        }
    }

// This code deletes a node from the linked list at the specified position.
// If the position is invalid, it does nothing.

void deleteNode(int position) {
    if (position >= 0 && position < size) {
        if (position == 0) {
            Node *temp = head;
            head = head->next;
            delete temp;
        } else {
            Node *current = head;
            Node *previous = NULL;
            for (int i = 0; i < position; i++) {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete current;
        }
        size--;
    } else {
        cout << "Invalid position: " << position << endl;
    }
}

};

int main() {


    return 0;
}