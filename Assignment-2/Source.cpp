#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void add(string data)
    {
        Node *node = new Node(data);
        if (isEmpty())
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    void remove(string data)
    {
        if (isEmpty())
        {
            return;
        }
        if (head->data == data)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *prev = head;
        Node *curr = head->next;
        while (curr != NULL)
        {
            if (curr->data == data)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void print()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};


class Skill
{
private:
    int id;
    int proficiency;

public:
    Skill()
    {
        id = 0;
        proficiency = 0;
    }
    Skill(int id, int proficiency)
    {
        this->id = id;
        this->proficiency = proficiency;
    }
    int getId()
    {
        return id;
    }
    int getProficiency()
    {
        return proficiency;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setProficiency(int proficiency)
    {
        this->proficiency = proficiency;
    }
};

class Resource
{
private:
    int id;
    int availability;
    Skill skill;

public:
    Resource()
    {
        id = 0;
        availability = 0;
    }
    Resource(int id, int availability, Skill skill)
    {
        this->id = id;
        this->availability = availability;
        this->skill = skill;
    }
    int getId()
    {
        return id;
    }
    int getAvailability()
    {
        return availability;
    }
    Skill getSkill()
    {
        return skill;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setAvailability(int availability)
    {
        this->availability = availability;
    }
    void setSkill(Skill skill)
    {
        this->skill = skill;
    }
};

class Task
{
public:
    string id;
    string dependencyId;
    int es;
    int ef;
    int ls;
    int lf;
    int slack;
    int duration;
    Task *next;
    Task *dependency;

    // getters and setters
    string getId()
    {
        return id;
    }

    int getEs()
    {
        return es;
    }

    int getEf()
    {
        return ef;
    }

    int getLs()
    {
        return ls;
    }

    int getLf()
    {
        return lf;
    }

    int getDuration()
    {
        return duration;
    }

    // Resource getResource()
    // {
    //     return resource;
    // }

    void setId(string id)
    {
        this->id = id;
    }

    void setEs(int es)
    {
        this->es = es;
    }

    void setEf(int ef)
    {
        this->ef = ef;
    }

    void setLs(int ls)
    {
        this->ls = ls;
    }

    void setLf(int lf)
    {
        this->lf = lf;
    }

    void setDuration(int duration)
    {
        this->duration = duration;
    }

    // void setResource(Resource resource)
    // {
    //     this->resource = resource;
    // }

    // constructors
    Task()
    {
        id = "";
        dependencyId = "";
        es = 0;
        ef = 0;
        ls = 0;
        lf = 0;
        duration = 0;
        next = nullptr;
    }

    Task(string id, int duration)
    {
        this->id = id;
        this->duration = duration;
        dependencyId = "";
        es = 0;
        ef = 0;
        ls = 0;
        lf = 0;
        next = nullptr;
    }

    Task(string id, int duration, Task *next)
    {
        this->id = id;
        this->duration = duration;
        this->next = next;
        es = 0;
        ef = 0;
        ls = 0;
        lf = 0;
    }

    Task(string id, int duration, Task *next, Resource resource)
    {
        this->id = id;
        this->duration = duration;
        this->next = next;
        // this->resource = resource;
        es = 0;
        ef = 0;
        ls = 0;
        lf = 0;
    }

    // destructor

    ~Task()
    {
        delete[] next;
    }

    // methods

    void print()
    {
        cout << id << setw(15) << duration << setw(15) << dependencyId << setw(15) << es << setw(15) << ef << setw(15) << ls << setw(15) << lf << endl;
    }
};

class TaskNode
{
public:
    Task *data;
    TaskNode *next;

    TaskNode(Task *data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class TaskLinkedList
{
public:
    TaskNode *head;
    TaskNode *tail;

    TaskLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void add(Task *data)
    {
        TaskNode *taskNode = new TaskNode(data);
        if (isEmpty())
        {
            head = taskNode;
            tail = taskNode;
        }
        else
        {
            tail->next = taskNode;
            tail = taskNode;
        }
    }

    void remove(Task *data)
    {
        if (isEmpty())
        {
            return;
        }
        if (head->data == data)
        {
            TaskNode *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        TaskNode *prev = head;
        TaskNode *curr = head->next;
        while (curr != NULL)
        {
            if (curr->data == data)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void print()
    {
        TaskNode *curr = head;
        while (curr != NULL)
        {
            cout << curr->data->id << " (" << curr->data->duration << " days)" << endl;
            curr = curr->next;
        }
    }
};

class Project
{

private:
    string id;
    int duration;
    Task *start;
    Task* end;

public:
    Project()
    {
        start = new Task();
        end = new Task();
        start->next = end;
    }

    Task *getStart()
    {
        return start;
    }

    Task *getEnd()
    {
        return end;
    }

    void setStart(Task *start)
    {
        this->start = start;
    }

    void setEnd(Task *end)
    {
        this->end = end;
    }

    void addTask(Task *task)
    {
        Task *temp = start;
        while (temp->next != end)
        {
            temp = temp->next;
        }
        temp->next = task;
        task->next = end;
        cout << "Task added successfully" << endl;
    }

    bool validateDependencyId(string dependencyId)
    {
        Task *temp = start;
        temp = temp->next;
        while (temp != end)
        {
            if (temp->getId() == dependencyId)
            {
                return true;
            }
            temp = temp->next;
        }
        cout << "Invalid dependency id" << endl;
        return false;
    }

    void AddTasks()
    {
        string id;
        char choice;
        int duration;
        Task *task = new Task();
        cout << "\n\nEnter task id: ";
        cin >> id;
        task->id = id;
        cout << "Enter task duration: ";
        cin >> duration;
        task->duration = duration;
        if (!isEmpty())
        {
            cout << "Does this task have any dependency? (y/n): ";
            cin >> choice;
            if (choice == 'y')
            {
                string dependencyId;
                cout << "Enter dependency id: ";
                cin >> dependencyId;
                if (validateDependencyId(dependencyId))
                {
                    task->dependencyId = dependencyId;
                    Task *temp = start;
                    while (temp != end)
                    {
                        if (temp->getId() == dependencyId)
                        {
                            task->dependency = temp;
                            break;
                        }
                        temp = temp->next;
                    }
                    if (task->dependency->ef > task->es) {
                        task->es = task->dependency->ef;
                    }
                    task->ef = task->duration + task->es;
                    addTask(task);
                }
                else
                {
                    cout << "Dependency id not found" << endl;
                    return;
                }
            }
            else if (choice == 'n')
            {
                task->dependencyId = "start";
                task->dependency = start;
                cout << "Enter Early Start: ";
                cin >> task->es;
                task->ef = task->duration + task->es;
                addTask(task);
            }
            else
            {
                cout << "Invalid choice" << endl;
                return;
            }
        }
        else
        {
            task->dependencyId = "start";
            task->dependency = start;
            task->es = 0;
            task->ef = task->duration;
            addTask(task);
        }
    }

    void PrintTaskDependencyList()
    {
        Task *temp = start;
        temp = temp->next;
        cout << "ID" << setw(15) << "Duration" << setw(15) << "Dependency ID" << setw(15) << "ES" << setw(15) << "EF" << setw(15) << "LS" << setw(15) << "LF" << endl;
        while (temp != end)
        {
            temp->print();
            temp = temp->next;
        }
    }

    void SetNthTaskDuration(string taskId, int duration)
    {
        Task *temp = start;
        while (temp->next != end)
        {
            if (temp->getId() == taskId)
            {
                temp->setDuration(duration);
                break;
            }
            temp = temp->next;
        }
    }

    void SetTaskDuration()
    {
        Task *temp = start;
        temp = temp->next;
        while (temp != end)
        {
            cout << "Enter duration of task " << temp->getId() << ": ";
            int duration;
            cin >> duration;
            temp->setDuration(duration);
            temp = temp->next;
        }
    }

    bool isEmpty()
    {
        if (start->next == end)
        {
            return true;
        }
        return false;
    }

    void CalculateBasicSchedule() {
        LinkedList *dependencyId = new LinkedList();
        Task *temp = start;
        temp = temp->next;
        while (temp != end) {
            Node* current = dependencyId->head;
            while (current != NULL) {
                if (current->data == temp->dependencyId) {
                    temp->dependency = temp->dependency->next;
                    break;
                }
                current = current->next;
            }
            dependencyId->add(temp->dependencyId);
            temp = temp->next;
        }

        TaskLinkedList *taskLinkedList = new TaskLinkedList();
        temp = start;
        temp = temp->next;
        while (temp != end) {
            bool exit = false;
            Node* current = dependencyId->head;
            while (current != NULL) {
                if (current->data == temp->id) {
                    exit = true;
                    break;
                }
                current = current->next;
            }
            if (exit) {
                temp = temp->next;
                continue;
            }
            taskLinkedList->add(temp);
            temp = temp->next;
        }

        taskLinkedList->print();
    }
};

/*
class TaskNode
{
public:
    Task *data;
    TaskNode *next;

    TaskNode(Task *data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class TaskLinkedList
{
public:
    TaskNode *head;
    TaskNode *tail;

    TaskLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void add(Task *data)
    {
        TaskNode *taskNode = new TaskNode(data);
        if (isEmpty())
        {
            head = taskNode;
            tail = taskNode;
        }
        else
        {
            tail->next = taskNode;
            tail = taskNode;
        }
    }

    void remove(Task *data)
    {
        if (isEmpty())
        {
            return;
        }
        if (head->data == data)
        {
            TaskNode *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        TaskNode *prev = head;
        TaskNode *curr = head->next;
        while (curr != NULL)
        {
            if (curr->data == data)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void print()
    {
        TaskNode *curr = head;
        while (curr != NULL)
        {
            cout << curr->data->id << " (" << curr->data->duration << " days)" << endl;
            curr = curr->next;
        }
    }
};
*/

void displayMenu()
{
    cout << "1. Add Resources" << endl;
    cout << "2. Add Tasks" << endl;
    cout << "3. Set Task Duration" << endl;
    cout << "4. Set nth Task Duration" << endl;
    cout << "5. Print Task Dependency List" << endl;
    cout << "6. Calculate Basic Schedule" << endl;
    cout << "7. Print Critical Tasks" << endl;
    cout << "8. Completion Time With Resources" << endl;
    cout << "9. Completion Time With Resource Proficiency" << endl;
    cout << "10. Exit" << endl;
}

void AddResources()
{
    /* code */
}

void PrintCriticalTasks()
{
    /* code */
}

void CompletionTimeWithResources()
{
    /* code */
}

void CompletionTimeWithResourceProficiency()
{
    /* code */
}

int main()
{

    Project p;
    while (true)
    {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddResources();
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
            PrintCriticalTasks();
            break;
        case 8:
            CompletionTimeWithResources();
            break;
        case 9:
            CompletionTimeWithResourceProficiency();
            break;
        case 10:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}