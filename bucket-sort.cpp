#include <iostream>
#include <math.h>
using namespace std;

void validate(float &num) {
    while (num < 0 || num >= 1) {
        cout << "\nEnter number in range of (0 - 1): ";
        cin >> num;
    }
}

const int SIZE = 10;

class Node {
    public:
    int data;
    Node* next;

    Node() : data(0), next(NULL) {}

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class List {
    private:
    Node* head;

    public:
    List() {
        this->head = NULL;
    }

    List(Node* head) {
        this->head = head;
    }

    void insertion(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else if (head->data >= newNode->data)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *traverse = head;
            while (traverse->next != NULL && traverse->next->data < newNode->data)
            {
                traverse = traverse->next;
            }
            newNode->next = traverse->next;
            traverse->next = newNode;
        }
    }

    Node* getHead() {
        return head;
    }
};

int main()
{
    float arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nEnter value: ";
        cin >> arr[i];
        validate(arr[i]);
    }

    List list[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        int index = floor(arr[i] * SIZE);
        list[index].insertion(arr[i]);
    }

    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (list[i].getHead() == NULL)
        {
            continue;
        }

        Node *traverse = list[i].getHead();
        while (traverse != NULL)
        {
            arr[count] = traverse->data;
            traverse = traverse->next;
            count++;
        }
    }

    cout << "\nSorted List: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}