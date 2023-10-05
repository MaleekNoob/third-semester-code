#include <iostream>
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
    string id;
    int es, ef, ls, lf, duration;
    Task** next, ** prev;
    Resource resource;
    int prevCount /*dependencies*/, nextCount /*dependents*/;

public:

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

    Task** getNext()
    {
        return next;
    }

    Task** getPrev()
    {
        return prev;
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

    void setNext(Task** next)
    {
        this->next = next;
    }

    void setPrev(Task** prev)
    {
        this->prev = prev;
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
        prev = nullptr;
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
        prev = nullptr;
    }

    Task(string id, int duration, Task** next, Task** prev)
    {
        this->id = id;
        this->duration = duration;
        this->next = next;
        this->prev = prev;
        es = 0;
        ef = 0;
        ls = 0;
        lf = 0;
    }

    Task(string id, int duration, Task** next, Task** prev, Resource resource)
    {
        this->id = id;
        this->duration = duration;
        this->next = next;
        this->prev = prev;
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
        delete[] prev;
    }

    // methods

    void addDependency(Task* dependency) {
        // dynamically increase ** next and add dependency to it
        Task** temp = new Task*[nextCount + 1];
        for (int i = 0; i < nextCount; i++) {
            temp[i] = next[i];
        }
        temp[nextCount] = dependency;
        nextCount++;
        delete[] next;
        next = temp;
    }

    void addDependent(Task* dependent) {
        // dynamically increase ** prev and add dependent to it
        Task** temp = new Task*[prevCount + 1];
        for (int i = 0; i < prevCount; i++) {
            temp[i] = prev[i];
        }
        temp[prevCount] = dependent;
        prevCount++;
        delete[] prev;
        prev = temp;
    }

};

class TaskList {
    
private:
    Task* start,* end;

public:
    TaskList() {
        start = new Task();
        end = new Task();
    }

    TaskList(Task* start, Task* end) {
        this->start = start;
        this->end = end;
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

    void addDependency() {
        /* code */
    }
};

class Project
{
private:
    int id;
    int duration;
    Task *tasks;
    int taskCount;
    int resourceCount;

public:
    Project()
    {
        id = 0;
        duration = 0;
        tasks = nullptr;
        taskCount = 0;
        resourceCount = 0;
    }
    Project(int id, int duration, Task *tasks, int taskCount, int resourceCount)
    {
        this->id = id;
        this->duration = duration;
        this->tasks = tasks;
        this->taskCount = taskCount;
        this->resourceCount = resourceCount;
    }
    int getId()
    {
        return id;
    }
    int getDuration()
    {
        return duration;
    }
    Task *getTasks()
    {
        return tasks;
    }
    int getTaskCount()
    {
        return taskCount;
    }
    int getResourceCount()
    {
        return resourceCount;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setDuration(int duration)
    {
        this->duration = duration;
    }
    void setTasks(Task *tasks)
    {
        this->tasks = tasks;
    }
    void setTaskCount(int taskCount)
    {
        this->taskCount = taskCount;
    }
    void setResourceCount(int resourceCount)
    {
        this->resourceCount = resourceCount;
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

void AddTasks() {
    /* code */
}

void SetTaskDuration() {
    /* code */
}

void SetNthTaskDuration() {
    /* code */
}

void PrintTaskDependencyList() {
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
                AddTasks();
                break;
            case 3:
                SetTaskDuration();
                break;
            case 4:
                SetNthTaskDuration();
                break;
            case 5:
                PrintTaskDependencyList();
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