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

class Task;

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

    void print();
};

class Task
{
public:
    string id;
    // string dependencyId;
    LinkedList *predecessorIds;
    int es;
    int ef;
    int ls;
    int lf;
    int slack;
    int duration;
    Task *next;
    // Task *dependency;
    TaskLinkedList *predecessors;

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

    // constructors
    Task()
    {
        id = "";
        es = 0;
        ef = 0;
        ls = 0;
        lf = 0;
        slack = 0;
        duration = 0;
        next = nullptr;
        predecessorIds = new LinkedList();
        predecessors = new TaskLinkedList();
    }

    Task(string id, int duration)
    {
        this->id = id;
        this->duration = duration;
        // dependencyId = "";
        es = 0;
        ef = 0;
        ls = 0;
        lf = 0;
        slack = 0;
        next = nullptr;
        predecessorIds = new LinkedList();
        predecessors = new TaskLinkedList();
    }

    // destructor

    ~Task()
    {
        delete[] next;
    }

    // methods

    void print()
    {
        cout << id << setw(15) << duration;
        Node* current = predecessorIds->head;
        string predecessor = "";
        while (current != NULL) {
            predecessor += current->data + " ";
            current = current->next;
        }
        cout << setw(15) << predecessor << setw(15) << es << setw(15) << ef << setw(15) << ls << setw(15) << lf << setw(15) << slack << endl;
    }
};

void TaskLinkedList::print()
{
    TaskNode *curr = head;
    while (curr != NULL)
    {
        cout << curr->data->id << endl;
        curr = curr->next;
    }
}

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
                int numberOfPredecessors = 0;
                cout << "Enter number of predecessors: ";
                cin >> numberOfPredecessors;
                for (int i = 0; i < numberOfPredecessors; i++) {
                    int predecessorCount;
                    LinkedList *tempPredecessorIds = new LinkedList();
                    char choice;
                    do {
                        string tem;
                        cout << "Enter predecessor id: ";
                        cin >> tem;
                        if (validateDependencyId(tem)) {
                            task->predecessorIds->add(tem);
                            Task *temp = start;
                            while (temp != end)
                            {
                                if (temp->getId() == tem)
                                {
                                    task->predecessors->add(temp);
                                    break;
                                }
                                temp = temp->next;
                            }
                            TaskNode *current = task->predecessors->head;
                            while (current != NULL)
                            {
                                if (tem == current->data->id)
                                {
                                    if (current->data->ef > task->es)
                                    {
                                        task->es = current->data->ef;
                                    }
                                }
                                current = current->next;
                            }
                            task->ef = task->duration + task->es;
                            addTask(task);
                        }
                        else
                        {
                            cout << "Invalid dependency id" << endl;
                            return;
                        }
                        tempPredecessorIds->add(tem);
                        predecessorCount++;
                        cout << "Do you want to add more predecessors? (y/n): ";
                        cin >> choice;
                    } while (choice == 'y');
                }
            }
            else if (choice == 'n')
            {
                task->predecessorIds->add("start");
                task->predecessors->add(start);
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
            task->predecessorIds->add("start");
            task->predecessors->add(start);
            task->es = 0;
            task->ef = task->duration;
            addTask(task);
        }
    }

    void PrintTaskDependencyList()
    {
        Task *temp = start;
        temp = temp->next;
        cout << "ID" << setw(15) << "Duration" << setw(15) << "Dependency ID" << setw(15) << "ES" << setw(15) << "EF" << setw(15) << "LS" << setw(15) << "LF" << setw(15) << "Slack" << endl;
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

    void ScheduleOptimization()
    {

        // Collect predecessor id of all tasks
        LinkedList *dependencyId = new LinkedList();
        Task *temp = start;
        temp = temp->next;
        while (temp != end)
        {
            Node *current = temp->predecessorIds->head;
            while (current != NULL)
            {
                dependencyId->add(current->data);
                current = current->next;
            }
            temp = temp->next;
        }
        cout << "Collected predecessor ids" << endl;
        dependencyId->print();  // start start A

        // Collect end tasks
        TaskLinkedList *taskLinkedList = new TaskLinkedList();
        temp = start;
        temp = temp->next;
        while (temp != end)
        {
            bool exit = false;
            Node *current = dependencyId->head;
            while (current != NULL)
            {
                if (current->data == temp->id)
                {
                    exit = true;
                    break;
                }
                current = current->next;
            }
            if (exit)
            {
                temp = temp->next;
                continue;
            }
            taskLinkedList->add(temp);
            temp = temp->next;
        }
        cout << "Collected end tasks" << endl;
        taskLinkedList->print();
        // B C

        // Calculate highest EF for LF calculation
        TaskNode *current = taskLinkedList->head;
        int tempLf = 0;
        while (current != NULL)
        {
            if (current->data->ef > tempLf)
            {
                tempLf = current->data->ef;
            }
            end->es = tempLf;
            end->ef = tempLf;
            end->ls = tempLf;
            end->lf = tempLf;
            end->predecessorIds->add(current->data->id);
            end->predecessors->add(current->data);
            current = current->next;
        }
        cout << "Calculated highest EF" << endl;
        cout << "Temp Lf: " << tempLf;

       int count = 0;
       TaskNode *iter;
       while (true) {
            count++;
            cout << "\nWhile loop iteration " << count << endl;
            bool exit = false;
            // Sort taskLinkedList such that if any taskNode has id equal to start then it should be at the end
            iter = taskLinkedList->head;
            TaskNode *prev = NULL;
            while (iter != NULL)
            {
                if (iter->data->id == "start")
                {
                    if (prev == NULL && iter->next == NULL)
                    {
                        break;
                    }
                    else if (iter == taskLinkedList->head && iter->next != NULL) {
                        taskLinkedList->head = iter->next;
                        iter->next = NULL;
                        taskLinkedList->tail->next = iter;
                        taskLinkedList->tail = iter;
                    }
                    else if (iter == taskLinkedList->tail) {
                        break;
                    }
                    else {
                        prev->next = iter->next;
                        iter->next = NULL;
                        taskLinkedList->tail->next = iter;
                        taskLinkedList->tail = iter;
                    }
                }
                prev = iter;
                iter = iter->next;
            }
            cout << "TaskLinkedList sorted" << endl;
            taskLinkedList->print();

            // remove duplicate id
            // iter = taskLinkedList->head;
            // while (iter != NULL)
            // {
            //     TaskNode *iter2 = iter->next;
            //     while (iter2 != NULL)
            //     {
            //         if (iter->data->id == iter2->data->id)
            //         {
            //             taskLinkedList->remove(iter2->data);
            //         }
            //         iter2 = iter2->next;
            //     }
            //     iter = iter->next;
            // }
            // cout << "Duplicate id removed" << endl;
            // taskLinkedList->print();

            // Solve each task in taskLinkedList only if its id isn't equal to "start"
            iter = taskLinkedList->head;
            while (iter != NULL) {
                exit = false;
                if (iter->data->id != "start") {
                    TaskLinkedList *previousTasks = new TaskLinkedList();
                    Task* traverse = start;
                    traverse = traverse->next;
                    while (traverse != NULL) {
                        Node* temp = traverse->predecessorIds->head;
                        while (temp != NULL) {
                            if (temp->data == iter->data->id) {
                                previousTasks->add(traverse);
                                break;
                            }
                            temp = temp->next;
                        }
                        traverse = traverse->next;
                    }
                    cout << endl << "Previous tasks of " << iter->data->id << ": " << endl;
                    previousTasks->print();
                    TaskNode *temp = previousTasks->head;
                    int tempLf = 10000;
                    while (temp != NULL)
                    {
                        if (temp->data->lf < tempLf)
                            tempLf = temp->data->ls;
                        temp = temp->next;
                    }
                    iter->data->lf = tempLf;
                    iter->data->ls = iter->data->lf - iter->data->duration;
                    iter->data->slack = iter->data->lf - iter->data->ef;
                    iter = iter->next;
                }
                else {
                    exit = true;
                    break;
                }
            }
            if (exit) {
                cout << "WE WON!!!!" << endl;
                break;
            }
            cout << "Solved each task in taskLinkedList" << endl;
            PrintTaskDependencyList();

            // Get predecessors of each task in taskLinkedList
            TaskLinkedList *tempTaskLinkedList = new TaskLinkedList();
            TaskNode* tem = taskLinkedList->head;
            while (tem != NULL) {
                TaskNode* temp = tem->data->predecessors->head;
                while (temp != NULL) {
                    if (temp->data->id == "") {
                        temp->data->id = "start";
                    }
                    cout << "Predecessor of " << tem->data->id << " is " << temp->data->id << endl;
                    tempTaskLinkedList->add(temp->data);
                    temp = temp->next;
                }
                tem = tem->next;
            }
            taskLinkedList = tempTaskLinkedList;
            cout << "Got predecessors of each task in taskLinkedList" << endl;
            taskLinkedList->print();
       }

       
    }

    void CalculateBasicSchedule() {

        ScheduleOptimization();
        PrintTaskDependencyList();
    }

    void PrintCriticalTasks()
    {
        ScheduleOptimization();
        Task *temp = start;
        temp = temp->next;
        cout << "Critical Tasks: ";
        while (temp != end)
        {
            if (temp->slack == 0)
            {
                cout << temp->id << " ";
            }
            temp = temp->next;
        }
    }
};

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

void CompletionTimeWithResources()
{
    /* code */
}

void CompletionTimeWithResourceProficiency()
{
    /* code */
}

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
            p.PrintCriticalTasks();
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