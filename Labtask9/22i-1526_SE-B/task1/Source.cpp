#include "EmployeeQueue.h"

int main() {
    Queue queue;

    while (true) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Show front" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
        {
            cout << "Enter name: ";
            string name;
            cin >> name;
            cout << "Enter ID: ";
            int id;
            cin >> id;
            cout << "Enter salary: ";
            double salary;
            cin >> salary;
            Node emp(name, id, salary);
            queue.enqueue(emp);
            break;
        }
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.showFront().printEmployeeData();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}