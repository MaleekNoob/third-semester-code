#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = -1;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class List {
    private:
    public:
    Node* head;
    Node* sorted;

    List() {
        sorted = NULL;
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

    void InputInSortedList(Node *newNode)
    {
        Node *newNode1 = new Node();
        newNode1->data = newNode->data;
        newNode1->next = NULL;
        if (sorted == NULL || sorted->data >= newNode1->data)
        {
            newNode1->next = sorted;
            sorted = newNode1;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < newNode1->data)
            {
                temp = temp->next;
            }
            newNode1->next = temp->next;
            temp->next = newNode1;
        }
    }

    Node *insertionSortList(Node *head)
    {
        Node *traverse = head;
        sorted = NULL;
        while (traverse != NULL)
        {
            InputInSortedList(traverse);
            cout << "\nSorted list be ";
            Node* sortTraverse = sorted;
            while (sortTraverse != NULL ) {
                cout << sortTraverse->data << " ";
                sortTraverse = sortTraverse->next;
            }
            traverse = traverse->next;
        }
        head = sorted;

        return head;
    }

    Node *reverseList(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *reversedList = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return reversedList;
    }

    bool isPalindrome(Node* head) {
        /* code */
    }
};

int main() {

    List list;
    list.insertAtEnd(-1);
    list.insertAtEnd(5);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(0);
    list.print();
    Node* kamal = list.insertionSortList(list.head);
    
    Node* traverse = kamal;
    cout << endl << "Sorted List: ";
    while (traverse != NULL) {
        cout << traverse->data << " ";
        traverse = traverse->next;
    }

    return 0;
}

