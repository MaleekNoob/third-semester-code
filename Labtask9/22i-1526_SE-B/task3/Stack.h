#include "Queue.h"

using namespace std;

class Stack
{
private:
    Queue<int> q1, q2;

    void Swap(Queue<int> &q1, Queue<int> &q2)
    {
        Queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

public:
    void enqueue(int x)
    {
        q1.enqueue(x);
    }

    int dequeue()
    {
        if (q1.isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        while (q1.size() > 1)
        {
            q2.enqueue(q1.peek());
            q1.dequeue();
        }

        int popped = q1.peek();
        q1.dequeue();

        // calling swap function
        Swap(q1, q2);

        return popped;
    }

    int top()
    {
        if (q1.isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        while (q1.size() > 1)
        {
            q2.enqueue(q1.peek());
            q1.dequeue();
        }

        int top = q1.peek();
        q2.enqueue(q1.peek());
        q1.dequeue();

        Swap(q1, q2);

        return top;
    }
};