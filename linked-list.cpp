#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Linked_List {
    private:
        Node* head;
        Node* tail;
    public:
        Linked_List() {
            head = NULL;
            tail = NULL;
        }

        void add_node(int n) {
            Node* temp = new Node;
            temp->data = n;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = tail->next;
            }
        }

        void display() {
            Node* temp = new Node;
            temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

        void insert_start(int n) {
            Node* temp = new Node;
            temp->data = n;
            temp->next = head;
            head = temp;
        }

        void insert_position(int pos, int n) {
            Node* pre = new Node;
            Node* cur = new Node;
            Node* temp = new Node;
            cur = head;
            for (int i = 1; i < pos; i++) {
                pre = cur;
                cur = cur->next;
            }
            temp->data = n;
            pre->next = temp;
            temp->next = cur;
        }

        void delete_first() {
            Node* temp = new Node;
            temp = head;
            head = head->next;
            delete temp;
        }

        void delete_last() {
            Node* current = new Node;
            Node* previous = new Node;
            current = head;
            while (current->next != NULL) {
                previous = current;
                current = current->next;
            }
            tail = previous;
            previous->next = NULL;
            delete current;
        }

        void delete_position(int pos) {
            Node* current = new Node;
            Node* previous = new Node;
            current = head;
            for (int i = 1; i < pos; i++) {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
        }
};

int main() {

    Linked_List a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.insert_position(3, 5);
    a.delete_first();
    a.display();

    return 0;
}
