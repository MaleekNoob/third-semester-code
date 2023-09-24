#include <iostream>
#include <stack>
using namespace std;

void CompareValue(stack<int> &St, int value)
{
    if (St.empty() || St.top() < value)
    {
        St.push(value);
        return;
    }
    else
    {
        int temp = St.top();
        St.pop();
        CompareValue(St, value);
        St.push(temp);
    }
}

void sort(stack<int> &St)
{
    if (St.empty())
    {
        return; // Base case: stack is already sorted or empty
    }
    int temp = St.top();
    St.pop();
    sort(St);               // Recursively sort the remaining stack
    CompareValue(St, temp); // Insert the popped element in its correct place
}

int main() {

    // unsorted stack
    stack<int> St;
    St.push(5);
    St.push(1);
    St.push(3);
    St.push(2);
    St.push(4);

    // sorted stack
    sort(St);

    if (St.empty()) {
        cout << "Exception";
        exit(1);
    }

    // print sorted stack
    cout << "Sorted stack: ";
    while (!St.empty()) {
        cout << St.top() << " ";
        St.pop();
    }


    return 0;
}