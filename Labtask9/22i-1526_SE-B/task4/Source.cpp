#include "robinround.h"

int main() {
    Queue<Task> taskQueue;
    int executionTime;
    char id;
    int timeSlice;
    cout << "\n\nRound Robin Scheduling\n\n";
    cout << "\nEnter time slice: ";
    cin >> timeSlice;

    while (true) {
        int choice;
        cout << "\n1. Add task\n2. Execute task\n3. Exit\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter task id: ";
            cin >> id;
            cout << "Enter execution time: ";
            cin >> executionTime;
            Task task;
            task.id = id;
            task.executionTime = executionTime;
            taskQueue.enqueue(task);
            break;
        }

        case 2:
        {
            if (taskQueue.isEmpty()) {
                cout << "No tasks to execute." << endl;
            }
            else {
                roundRobin(taskQueue, timeSlice);
            }
            break;
        }

        case 3:
        {
            exit(0);
            break;
        }

        default:
            break;
        }

    }

    return 0;
}