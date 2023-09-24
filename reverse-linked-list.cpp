// Reverse linked list using recursion
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
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
};

int main()
{
    // Creating a sample linked list
    List l;
    l.InsertAtFront(3);
    l.InsertAtFront(5);
    l.InsertAtFront(7);

    cout << "Original Linked List: ";
    l.print();

    // Reverse the linked list
    l.reverseList(l.returnNode(0));

    cout << "Reversed Linked List: ";
    l.print();

    // Clean up memory (not shown in your original code)
    while (l.getHead() != nullptr)
    {
        Node *temp = l.getHead();
        l.setHead(l.getHead()->next);
        delete temp;
    }

    return 0;
}