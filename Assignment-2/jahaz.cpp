#include <iostream>
using namespace std;

// Class for Skill
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

// Class for Resource
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

// Class for Task
class Task
{
private:
    int id;
    int duration;
    int startTime;
    int *dependencies;
    int dependencyCount;
    Skill skill;

public:
    Task()
    {
        id = 0;
        duration = 0;
        startTime = 0;
        dependencies = nullptr;
        dependencyCount = 0;
    }
    Task(int id, int duration, int startTime, int *dependencies, int dependencyCount, Skill skill)
    {
        this->id = id;
        this->duration = duration;
        this->startTime = startTime;
        this->dependencies = dependencies;
        this->dependencyCount = dependencyCount;
        this->skill = skill;
    }
    int getId()
    {
        return id;
    }
    int getDuration()
    {
        return duration;
    }
    int getStartTime()
    {
        return startTime;
    }
    int *getDependencies()
    {
        return dependencies;
    }
    int getDependencyCount()
    {
        return dependencyCount;
    }
    Skill getSkill()
    {
        return skill;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setDuration(int duration)
    {
        this->duration = duration;
    }
    void setStartTime(int startTime)
    {
        this->startTime = startTime;
    }
    void setDependencies(int *dependencies)
    {
        this->dependencies = dependencies;
    }
    void setDependencyCount(int dependencyCount)
    {
        this->dependencyCount = dependencyCount;
    }
    void setSkill(Skill skill)
    {
        this->skill = skill;
    }
};

// Class for Project
class Project
{
private:
    int id;
    int duration;
    Task *tasks;
    int taskCount;
    Resource *resources;
    int resourceCount;

public:
    Project()
    {
        id = 0;
        duration = 0;
        tasks = nullptr;
        taskCount = 0;
        resources = nullptr;
        resourceCount = 0;
    }
    Project(int id, int duration, Task *tasks, int taskCount, Resource *resources, int resourceCount)
    {
        this->id = id;
        this->duration = duration;
        this->tasks = tasks;
        this->taskCount = taskCount;
        this->resources = resources;
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
    Resource *getResources()
    {
        return resources;
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
    void setResources(Resource *resources)
    {
        this->resources = resources;
    }
    void setResourceCount(int resourceCount)
    {
        this->resourceCount = resourceCount;
    }
};

// void addResource()

int main() {

    int taskCount, resourceCount, skillCount;
    cout << "Enter number of tasks: ";
    cin >> taskCount;
    for (int i = 0; i < taskCount; i++) {
        int id, duration, startTime, dependencyCount;
        cout << "Enter task id: ";
        cin >> i;
    }
    return 0;
}