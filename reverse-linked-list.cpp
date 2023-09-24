// Reverse linked list using recursion
#include <iostream>
#include <cassert>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

class List
{
private:
    Node *head;
    int size;

public:
    List()
    {
        head = NULL;
        size = 0;
    }

    ~List()
    {
        delete head;
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    bool IsEmpty()
    {
        if (size = 0)
            return true;
        return false;
    }

    void InsertAtFront(int x)
    {
        Node *ptr = new Node;
        ptr->data = x;
        ptr->next = head;
        head = ptr;
        size++;
    }

    void InsertAtLast(int x)
    {
        Node *ptr = new Node;
        ptr->data = x;
        ptr->next = NULL;

        if (head == NULL)
        {
            head = ptr;
            size++;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = ptr;
            size++;
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

    void deleteNode(int position)
    {
        if (position >= 0 && position < size)
        {
            if (position == 0)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                Node *current = head;
                Node *previous = NULL;
                for (int i = 0; i < position; i++)
                {
                    previous = current;
                    current = current->next;
                }
                previous->next = current->next;
                delete current;
            }
            size--;
        }
        else
        {
            cout << "Invalid position: " << position << endl;
        }
    }

    void print()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    Node *reverseList(Node *start)
    {
        if (start->next == NULL)
        {
            head = start;
            return start;
        }
        Node* temp = new Node;
        temp = reverseList(start->next);
        temp->next = start;
        start->next = NULL;
        return start;
    }

    Node *returnNode(int index)
    {
        if (index < 0 || head == nullptr)
        {
            return nullptr; // Invalid index or empty list
        }

        Node *current = head;
        int counter = 0;

        while (current != nullptr)
        {
            if (counter == index)
            {
                return current; // Found the node at the given index
            }
            current = current->next;
            counter++;
        }

        return nullptr; // Index out of range
    }

    Node* getHead() {
        return head;
    }

    void setHead(Node* n) {
        head = n;
    }

    bool testReverseList()
    {
        bool success = true;

        // Test case 1: Reverse a list with one node
        Node *head = new Node(1);
        Node *reversed = reverseList(head);
        if (reversed != head)
        {
            success = false;
        }

        // Test case 2: Reverse a list with multiple nodes
        Node *node1 = new Node(1);
        Node *node2 = new Node(2);
        Node *node3 = new Node(3);
        node1->next = node2;
        node2->next = node3;
        Node *reversed2 = reverseList(node1);
        if (reversed2 != node3 || reversed2->next != node2 || reversed2->next->next != node1 || reversed2->next->next->next != NULL)
        {
            success = false;
        }

        // Test case 3: Reverse a list with only two nodes
        Node *node4 = new Node(4);
        Node *node5 = new Node(5);
        node4->next = node5;
        Node *reversed3 = reverseList(node4);
        if (reversed3 != node5 || reversed3->next != node4 || reversed3->next->next != NULL)
        {
            success = false;
        }

        return success;
    }
};

int main()
{
    List l;
    if (l.testReverseList()) {
        cout << "Success!" << endl;
    }
    else {
        cout << "Failure!" << endl;
    }

    return 0;
}