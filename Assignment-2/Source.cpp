#include "Header.h"

int main() {

    Project p;
    while (true)
    {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (!cin)
        {
            cout << "Invalid choice" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            p.AddResources();
            break;
        case 2:
            p.AddTasks();
            break;
        case 3:
            p.SetTaskDuration();
            break;
        case 4:
        {
            cout << "Enter task id: ";
            string taskId;
            cin >> taskId;
            cout << "Enter task duration: ";
            int duration;
            cin >> duration;
            p.SetNthTaskDuration(taskId, duration);
            break;
        }
        case 5:
            p.PrintTaskDependencyList();
            break;
        case 6:
            p.CalculateBasicSchedule();
            break;
        case 7:
            p.PrintCriticalTasks();
            break;
        case 8:
            p.CompletionTimeWithResources();
            break;
        case 9:
            p.CompletionTimeWithResourceProficiency();
            break;
        case 10:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}