#include "Stack.h"

int main() {
    Stack s;

    while (true) {
        cout << "1. enqueue" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int x;
            cout << "Enter the element to enqueue: ";
            cin >> x;
            s.enqueue(x);
            break;
        case 2:
            cout << "Popped element: " << s.dequeue() << endl;
            break;
        case 3:
            cout << "Top element: " << s.top() << endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
