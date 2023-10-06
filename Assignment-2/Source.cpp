#include <iostream>
#include <iomanip>
using namespace std;

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

class Task {
private:
    Resource resource;

public:
    string id, dependencyId;
    int es, ef, ls, lf, duration, taskCount;
    Task* next;
    Task* dependency;

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

    Resource getResource()
    {
        return resource;
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

    void setResource(Resource resource)
    {
        this->resource = resource;
    }

    // constructors
    Task()
    {
        id = "";
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
        es = 0;
        ef = 0;
        ls = 0;
        lf = 0;
        next = nullptr;
    }

    Task(string id, int duration, Task* next)
    {
        this->id = id;
        this->duration = duration;
        this->next = next;
        es = 0;
        ef = 0;
        ls = 0;
        lf = 0;
    }

    Task(string id, int duration, Task* next, Resource resource)
    {
        this->id = id;
        this->duration = duration;
        this->next = next;
        this->resource = resource;
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

    void print() {
        cout << id << setw(15) << duration << setw(15) << dependencyId << setw(15) << es << setw(15) << ef << setw(15) << ls << setw(15) << lf << endl;
        // cout << "Task resource id: " << resource.getId() << endl;
        // cout << "Task resource availability: " << resource.getAvailability() << endl;
        // cout << "Task resource skill id: " << resource.getSkill().getId() << endl;
        // cout << "Task resource skill proficiency: " << resource.getSkill().getProficiency() << endl;
    }

};

class Project {
    
private:
    string id;
    int duration;
    Task* start,* end;

public:
    Project() {
        start = new Task();
        end = new Task();
        start->next = end;
    }

    Task* getStart() {
        return start;
    }

    Task* getEnd() {
        return end;
    }

    void setStart(Task* start) {
        this->start = start;
    }

    void setEnd(Task* end) {
        this->end = end;
    }

    void addTask(Task* task) {
        Task* temp = start;
        while(temp->next != end) {
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
        if (!isEmpty()) {
            cout << "Does this task have any dependency? (y/n): ";
            cin >> choice;
            if (choice == 'y')
            {
                string dependencyId;
                cout << "Enter dependency id: ";
                cin >> dependencyId;
                if(validateDependencyId(dependencyId)) {
                    task->dependencyId = dependencyId;
                    Task* temp = start;
                    while(temp->next != end) {
                        if(temp->getId() == dependencyId) {
                            task->dependency = temp;
                            break;
                        }
                        temp = temp->next;
                    }
                    task->es = task->dependency->getEf();
                    task->ef = task->duration + task->es;
                    addTask(task);
                }
                else {
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
        Task* temp = start;
        temp = temp->next;
        while(temp != end) {
            cout << "Enter duration of task " << temp->getId() << ": ";
            int duration;
            cin >> duration;
            temp->setDuration(duration);
            temp = temp->next;
        }
    }

    bool isEmpty() {
        if(start->next == end) {
            return true;
        }
        return false;
    }

};

void displayMenu() {
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

void AddResources() {
    /* code */
}

void CalculateBasicSchedule() {
    /* code */
}

void PrintCriticalTasks() {
    /* code */
}

void CompletionTimeWithResources() {
    /* code */
}

void CompletionTimeWithResourceProficiency() {
    /* code */
}

int main() {

    Project p;
    while (true) {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
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
                CalculateBasicSchedule();
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
                cout << "Invalid choice" << endl;}
    }

    return 0;
}