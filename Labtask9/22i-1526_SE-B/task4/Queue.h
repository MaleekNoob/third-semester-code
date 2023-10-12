#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void enqueue(const T &data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    T peek() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        else
        {
            return front->data;
        }
    }

    int size()
    {
        int count = 0;
        Node *temp = front;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};
