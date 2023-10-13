/*
Name: Maleek Hussain Ali
Section: SE (B)
Roll Number: 22i-1526
Course: Data Structures
Assignment 2
*/

#include <iostream>
#include <iomanip>
#include <math.h>
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
    string id;
    float proficiency;

public:
    Skill()
    {
        id = "";
        proficiency = 0;
    }
    Skill(string id, float proficiency)
    {
        this->id = id;
        this->proficiency = proficiency;
    }
    string getId()
    {
        return id;
    }
    float getProficiency()
    {
        return proficiency;
    }
    void setId(string id)
    {
        this->id = id;
    }
    void setProficiency(float proficiency)
    {
        this->proficiency = proficiency;
    }
};

class Resource
{
private:
    string id;
    int availability;
    Skill skill;

public:
    Resource()
    {
        id = "";
        availability = 0;
    }
    Resource(string id, int availability, Skill skill)
    {
        this->id = id;
        this->availability = availability;
        this->skill = skill;
    }
    string getId()
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
    LinkedList *predecessorIds;
    int es;
    int ef;
    int ls;
    int lf;
    int slack;
    int duration;
    Task *next;
    TaskLinkedList *predecessors;
    Resource *resource;
    bool isResourceAdded;

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

    Resource *getResource()
    {
        return resource;
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

    void setResource(Resource *resource)
    {
        this->resource = resource;
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
        isResourceAdded = false;
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
        isResourceAdded = false;
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
        Node *current = predecessorIds->head;
        string predecessor = "";
        while (current != NULL)
        {
            predecessor += current->data + " ";
            current = current->next;
        }
        cout << setw(15) << predecessor << setw(15) << es << setw(15) << ef << setw(15) << ls << setw(15) << lf << setw(15) << slack << endl;
    }

    void printForResource()
    {
        cout << id << setw(15) << duration;
        Node *current = predecessorIds->head;
        string predecessor = "";
        while (current != NULL)
        {
            predecessor += current->data + " ";
            current = current->next;
        }
        cout << setw(15) << predecessor << setw(15) << es << setw(15) << ef << setw(15) << slack << endl;
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
    Task *end;

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

    void validationInt(int &num) {
        while (num < 0) {
            cout << "Enter a valid number (The number should be positive): ";
            cin >> num;
        }
    }

    void AddResources()
    {
        Task *temp = start;
        temp = temp->next;
        while (temp != end)
        {
            string resourceId;
            int resourceAvailability;
            string resourceSkillId;
            float resourceSkillProficiency;
            cout << "Enter resource id for task " << temp->getId() << ": ";
            cin >> resourceId;
            cout << "Enter resource availability for task " << temp->getId() << ": ";
            cin >> resourceAvailability;
            validationInt(resourceAvailability);
            cout << "Enter resource skill id for task " << temp->getId() << ": ";
            cin >> resourceSkillId;
            do
            {
                cout << "Enter resource skill proficiency for task " << temp->getId() << ": ";
                cin >> resourceSkillProficiency;
            } while (resourceSkillProficiency < 0 || resourceSkillProficiency > 1);
            Skill skill(resourceSkillId, resourceSkillProficiency);
            Resource *resource = new Resource(resourceId, resourceAvailability, skill);
            temp->setResource(resource);
            temp->isResourceAdded = true;
            temp = temp->next;
        }
    }

    void AddTasks()
    {
        string id;
        char choice;
        int duration;
        Task *task = new Task();

        // Prompt the user for task details
        cout << "\n\nEnter task id: ";
        cin >> id;
        task->id = id;
        cout << "Enter task duration: ";
        cin >> duration;
        validationInt(duration);
        task->duration = duration;

        // Check if there are existing tasks in the project
        if (!isEmpty())
        {
            // Prompt the user to specify task dependencies
            cout << "Does this task have any dependency? (y/n): ";
            cin >> choice;

            if (choice == 'y')
            {
                int numberOfPredecessors = 0;

                // Prompt the user for the number of task predecessors
                cout << "Enter number of predecessors: ";
                cin >> numberOfPredecessors;
                validationInt(numberOfPredecessors);

                for (int i = 0; i < numberOfPredecessors; i++)
                {
                    int predecessorCount;
                    LinkedList *tempPredecessorIds = new LinkedList();
                    char choice;
                    string tem;

                    // Prompt the user for predecessor task ID
                    cout << "Enter predecessor id: ";
                    cin >> tem;

                    // Validate the dependency ID
                    if (validateDependencyId(tem))
                    {
                        task->predecessorIds->add(tem);

                        // Find the corresponding predecessor task
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

                        // Update Early Start (ES) based on predecessor's Early Finish (EF)
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

                        // Calculate Early Finish (EF) for the current task
                        task->ef = task->duration + task->es;

                        // Add the task to the project schedule
                        addTask(task);
                    }
                    else
                    {
                        cout << "Invalid dependency id" << endl;
                        return;
                    }

                    tempPredecessorIds->add(tem);
                    predecessorCount++;
                }
            }
            else if (choice == 'n')
            {
                // Set the task as dependent on the project start
                task->predecessorIds->add("start");
                task->predecessors->add(start);

                // Prompt the user to enter Early Start (ES)
                cout << "Enter Early Start: ";
                cin >> task->es;

                // Calculate Early Finish (EF) for the current task
                task->ef = task->duration + task->es;

                // Add the task to the project schedule
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
            // If there are no existing tasks, set the current task as dependent on the project start
            task->predecessorIds->add("start");
            task->predecessors->add(start);

            // Initialize Early Start (ES) and Early Finish (EF) based on user input
            task->es = 0;
            task->ef = task->duration;

            // Add the task to the project schedule
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
            validationInt(duration);
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

        int count = 0;
        TaskNode *iter;
        while (true)
        {
            count++;
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
                    else if (iter == taskLinkedList->head && iter->next != NULL)
                    {
                        taskLinkedList->head = iter->next;
                        iter->next = NULL;
                        taskLinkedList->tail->next = iter;
                        taskLinkedList->tail = iter;
                    }
                    else if (iter == taskLinkedList->tail)
                    {
                        break;
                    }
                    else
                    {
                        prev->next = iter->next;
                        iter->next = NULL;
                        taskLinkedList->tail->next = iter;
                        taskLinkedList->tail = iter;
                    }
                }
                prev = iter;
                iter = iter->next;
            }

            // Solve each task in taskLinkedList only if its id isn't equal to "start"
            iter = taskLinkedList->head;
            while (iter != NULL)
            {
                exit = false;
                if (iter->data->id != "start")
                {
                    TaskLinkedList *previousTasks = new TaskLinkedList();
                    Task *traverse = start;
                    traverse = traverse->next;
                    while (traverse != NULL)
                    {
                        Node *temp = traverse->predecessorIds->head;
                        while (temp != NULL)
                        {
                            if (temp->data == iter->data->id)
                            {
                                previousTasks->add(traverse);
                                break;
                            }
                            temp = temp->next;
                        }
                        traverse = traverse->next;
                    }
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
                else
                {
                    exit = true;
                    break;
                }
            }
            if (exit)
            {
                break;
            }

            // Get predecessors of each task in taskLinkedList
            TaskLinkedList *tempTaskLinkedList = new TaskLinkedList();
            TaskNode *tem = taskLinkedList->head;
            while (tem != NULL)
            {
                TaskNode *temp = tem->data->predecessors->head;
                while (temp != NULL)
                {
                    if (temp->data->id == "")
                    {
                        temp->data->id = "start";
                    }
                    tempTaskLinkedList->add(temp->data);
                    temp = temp->next;
                }
                tem = tem->next;
            }
            taskLinkedList = tempTaskLinkedList;
        }
    }

    void CalculateBasicSchedule()
    {

        ScheduleOptimization();
        PrintTaskDependencyList();

        int tempEF = 0;
        Task *traverse = start;
        traverse = traverse->next;
        while (traverse != end)
        {
            if (tempEF < traverse->ef)
            {
                tempEF = traverse->ef;
            }
            traverse = traverse->next;
        }

        cout << "Time: " << tempEF << endl;
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

        int tempEF = 0;
        Task *traverse = start;
        traverse = traverse->next;
        while (traverse != end)
        {
            if (tempEF < traverse->ef)
            {
                tempEF = traverse->ef;
            }
            traverse = traverse->next;
        }

        cout << "Time: " << tempEF << endl;
    }

    void FrontPass()
    {
        // check that all tasks have resource
        Task *traverse = start;
        traverse = traverse->next;
        while (traverse != end)
        {
            if (!traverse->isResourceAdded)
            {
                cout << "All tasks must have resource" << endl;
                cout << "Task " << traverse->id << " doesn't have resource" << endl;
                return;
            }
            traverse = traverse->next;
        }

        // get tasks with predecessor id "start"
        TaskLinkedList *tasks = new TaskLinkedList();
        traverse = start;
        traverse = traverse->next;
        while (traverse != NULL)
        {
            Node *temp = traverse->predecessorIds->head;
            while (temp != NULL)
            {
                if (temp->data == "start")
                {
                    tasks->add(traverse);
                    break;
                }
                temp = temp->next;
            }
            traverse = traverse->next;
        }

        while (true)
        {
            if (tasks->head == NULL)
            {
                break;
            }
            // sort such that if any task has id equal to "end" then it should be at the end
            TaskNode *iter = tasks->head;
            TaskNode *prev = NULL;
            while (iter != NULL)
            {
                if (iter->data->id == "end")
                {
                    if (prev == NULL && iter->next == NULL)
                    {
                        break;
                    }
                    else if (iter == tasks->head && iter->next != NULL)
                    {
                        tasks->head = iter->next;
                        iter->next = NULL;
                        tasks->tail->next = iter;
                        tasks->tail = iter;
                    }
                    else if (iter == tasks->tail)
                    {
                        break;
                    }
                    else
                    {
                        prev->next = iter->next;
                        iter->next = NULL;
                        tasks->tail->next = iter;
                        tasks->tail = iter;
                    }
                }
                prev = iter;
                iter = iter->next;
            }

            // traverse over each element in tasks and store its predecessor IDs in a new linked list
            LinkedList *predecessorIds = new LinkedList();
            iter = tasks->head;
            while (iter != NULL)
            {
                Node *temp = iter->data->predecessorIds->head;
                while (temp != NULL)
                {
                    predecessorIds->add(temp->data);
                    temp = temp->next;
                }
                iter = iter->next;
            }

            // check if any element in predecessorIds repeats more than once then store it in a new linked list called resourceCriticalTaskPredecessor
            LinkedList *resourceCriticalTaskPredecessor = new LinkedList();
            Node *current = predecessorIds->head;
            while (current != NULL)
            {
                Node *temp = current->next;
                if (temp != NULL && current->data == temp->data)
                {
                    Node *temp2 = resourceCriticalTaskPredecessor->head;
                    bool flag = false;
                    while (temp2 != NULL)
                    {
                        if (temp2->data == current->data)
                        {
                            flag = true;
                            break;
                        }
                        temp2 = temp2->next;
                    }
                    if (!flag)
                    {
                        resourceCriticalTaskPredecessor->add(current->data);
                    }
                }
                current = current->next;
            }

            // traverse through all tasks and check if any task has predecessor id equal to any task in resourceCriticalTaskPredecessor then store it in a new linked list called resourceCriticalTasks
            TaskLinkedList *resourceCriticalTasks = new TaskLinkedList();
            iter = tasks->head;
            while (iter != NULL)
            {
                Node *temp = iter->data->predecessorIds->head;
                while (temp != NULL)
                {
                    Node *temp2 = resourceCriticalTaskPredecessor->head;
                    while (temp2 != NULL)
                    {
                        if (temp->data == temp2->data)
                        {
                            resourceCriticalTasks->add(iter->data);
                            break;
                        }
                        temp2 = temp2->next;
                    }
                    temp = temp->next;
                }
                iter = iter->next;
            }

            // traverse through resourceCriticalTasks and if any element's specific resource id repeats more than once then store that resource id in a new linked list called resourceCriticalTasksId
            LinkedList *resourceCriticalTasksId = new LinkedList();
            iter = resourceCriticalTasks->head;
            while (iter != NULL)
            {
                TaskNode *tem2 = iter->next;
                while (tem2 != NULL)
                {
                    if (iter->data->resource->getId() == tem2->data->resource->getId())
                    {
                        resourceCriticalTasksId->add(iter->data->resource->getId());
                        break;
                    }
                    tem2 = tem2->next;
                }
                iter = iter->next;
            }

            // traverse through all elements in resourceCriticalTasks and check if any element's specific resource id repeats more than once then store it in a new linked list called criticalTasksId
            LinkedList *criticalTasksId = new LinkedList();
            iter = resourceCriticalTasks->head;
            while (iter != NULL)
            {
                Node *tem2 = resourceCriticalTasksId->head;
                while (tem2 != NULL)
                {
                    if (iter->data->resource->getId() == tem2->data)
                    {
                        criticalTasksId->add(iter->data->id);
                        break;
                    }
                    tem2 = tem2->next;
                }
                iter = iter->next;
            }

            // From the tasks list, get all the elements which are not in criticalTasksId and store them in a new linked list called normalTasks
            TaskLinkedList *normalTasks = new TaskLinkedList();
            iter = tasks->head;
            while (iter != NULL)
            {
                Node *temp = criticalTasksId->head;
                bool flag = false;
                while (temp != NULL)
                {
                    if (iter->data->id == temp->data)
                    {
                        flag = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (!flag)
                {
                    normalTasks->add(iter->data);
                }
                iter = iter->next;
            }

            // From the tasks list, get all the elements which are in criticalTasksId and store them in a new linked list called criticalTasks
            TaskLinkedList *criticalTasks = new TaskLinkedList();
            iter = tasks->head;
            while (iter != NULL)
            {
                Node *temp = criticalTasksId->head;
                bool flag = false;
                while (temp != NULL)
                {
                    if (iter->data->id == temp->data)
                    {
                        flag = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (flag)
                {
                    criticalTasks->add(iter->data);
                }
                iter = iter->next;
            }

            // solve each element in criticalTasks
            int tempES = 0;
            bool flag = false;
            iter = criticalTasks->head;
            while (iter != NULL)
            {
                TaskNode *temporaryPredecessor = iter->data->predecessors->head;
                while (temporaryPredecessor != NULL)
                {
                    if (tempES < temporaryPredecessor->data->ef)
                    {
                        tempES = temporaryPredecessor->data->ef;
                    }
                    temporaryPredecessor = temporaryPredecessor->next;
                }
                iter = iter->next;
            }

            // sort criticalTasks according to earliest start (from lowest to highest), if any task has same earliest start then sort according to duration (from highest to lowest) using selection sort
            iter = criticalTasks->head;
            while (iter != NULL)
            {
                TaskNode *temp2 = iter->next;
                while (temp2 != NULL)
                {
                    if (iter->data->es > temp2->data->es)
                    {
                        Task *temp3 = iter->data;
                        iter->data = temp2->data;
                        temp2->data = temp3;
                    }
                    else if (iter->data->es == temp2->data->es)
                    {
                        if (iter->data->duration < temp2->data->duration)
                        {
                            Task *temp3 = iter->data;
                            iter->data = temp2->data;
                            temp2->data = temp3;
                        }
                    }
                    temp2 = temp2->next;
                }
                iter = iter->next;
            }

            iter = criticalTasks->head;
            while (iter != NULL)
            {
                flag = false;
                if (iter->data->id != "end")
                {
                    iter->data->es = tempES;
                    iter->data->ef = iter->data->es + iter->data->duration;
                    tempES = iter->data->ef;
                    iter = iter->next;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }

            // solve each element in normalTasks
            iter = normalTasks->head;
            while (iter != NULL)
            {
                flag = false;
                if (iter->data->id != "end")
                {
                    TaskNode *temporaryPredecessor = iter->data->predecessors->head;
                    int tempES = 0;
                    while (temporaryPredecessor != NULL)
                    {
                        if (tempES < temporaryPredecessor->data->ef)
                        {
                            tempES = temporaryPredecessor->data->ef;
                        }
                        temporaryPredecessor = temporaryPredecessor->next;
                    }
                    iter->data->es = tempES;
                    iter->data->ef = iter->data->es + iter->data->duration;
                    iter = iter->next;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }

            // get next tasks
            TaskLinkedList *nextTasks = new TaskLinkedList();
            TaskNode *tempTask = tasks->head;
            while (tempTask != NULL)
            {
                traverse = start;
                traverse = traverse->next;
                while (traverse != NULL)
                {
                    Node *temp = traverse->predecessorIds->head;
                    while (temp != NULL)
                    {
                        if (temp->data == tempTask->data->id)
                        {
                            nextTasks->add(traverse);
                            break;
                        }
                        temp = temp->next;
                    }
                    traverse = traverse->next;
                }
                tempTask = tempTask->next;
            }
            tasks = nextTasks;
        }
    }

    void BackPass()
    {
        Task *traverse = start;
        // set predecessors and predecessor ids of end task
        LinkedList *alltasksId = new LinkedList();
        traverse = start;
        traverse = traverse->next;
        while (traverse != end)
        {
            alltasksId->add(traverse->id);
            traverse = traverse->next;
        }

        // traverse through entire task list again and if any precedent of particular element is present then it won't be added in endTaskId
        traverse = start;
        traverse = traverse->next;
        while (traverse != end)
        {
            Node *temp = traverse->predecessorIds->head;
            while (temp != NULL)
            {
                alltasksId->remove(temp->data);
                temp = temp->next;
            }
            traverse = traverse->next;
        }
        cout << "\nAll tasks id: ";
        alltasksId->print();

        Node *endpredecessors = alltasksId->head;
        while (endpredecessors != NULL)
        {
            end->predecessorIds->add(endpredecessors->data);
            endpredecessors = endpredecessors->next;
        }
    }

    void CompletionTimeWithResources()
    {
        ScheduleOptimization();
        FrontPass();
        PrintSchedule();

        int tempEF = 0;
        Task *traverse = start;
        traverse = traverse->next;
        while (traverse != end)
        {
            if (tempEF < traverse->ef)
            {
                tempEF = traverse->ef;
            }
            traverse = traverse->next;
        }

        cout << "Time: " << tempEF << endl;
    }

    void CompletionTimeWithResourceProficiency()
    {
        // check that all tasks have resource
        Task *traverse = start;
        traverse = traverse->next;
        while (traverse != end)
        {
            if (!traverse->isResourceAdded)
            {
                cout << "All tasks must have resource" << endl;
                cout << "Task " << traverse->id << " doesn't have resource" << endl;
                return;
            }
            traverse = traverse->next;
        }

        // calculate completion time for each task
        traverse = start;
        traverse = traverse->next;
        while (traverse != end)
        {
            float ans = traverse->duration / traverse->resource->getSkill().getProficiency();
            traverse->duration = ceil(ans);
            traverse = traverse->next;
        }
        CompletionTimeWithResources();

        int tempEF = 0;
        traverse = start;
        traverse = traverse->next;
        while (traverse != end)
        {
            if (tempEF < traverse->ef)
            {
                tempEF = traverse->ef;
            }
            traverse = traverse->next;
        }

        cout << "Time: " << tempEF << endl;
    }

    void PrintSchedule()
    {
        Task *temp = start;
        temp = temp->next;
        cout << "ID" << setw(15) << "Duration" << setw(15) << "Dependency ID" << setw(15) << "ES" << setw(15) << "EF" << setw(15) << "Slack" << endl;
        while (temp != end)
        {
            temp->printForResource();
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