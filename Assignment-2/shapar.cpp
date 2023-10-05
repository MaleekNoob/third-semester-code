#include <iostream>
using namespace std;

// Class for Skill
class Skill {
private:
    int id;
    int proficiency;
public:
    Skill() {
        id = 0;
        proficiency = 0;
    }
    Skill(int id, int proficiency) {
        this->id = id;
        this->proficiency = proficiency;
    }
    int getId() {
        return id;
    }
    int getProficiency() {
        return proficiency;
    }
    void setId(int id) {
        this->id = id;
    }
    void setProficiency(int proficiency) {
        this->proficiency = proficiency;
    }
};

// Class for Resource
class Resource {
private:
    int id;
    int availability;
    Skill skill;

public:
    Resource() {
        id = 0;
        availability = 0;
    }
    Resource(int id, int availability, Skill skill) {
        this->id = id;
        this->availability = availability;
        this->skill = skill;
    }
    int getId() {
        return id;
    }
    int getAvailability() {
        return availability;
    }
    Skill getSkill() {
        return skill;
    }
    void setId(int id) {
        this->id = id;
    }
    void setAvailability(int availability) {
        this->availability = availability;
    }
    void setSkill(Skill skill) {
        this->skill = skill;
    }
};

// Class for Task
class Task {
private:
    int id;
    int duration;
    int startTime;
    int* dependencies;
    int dependencyCount;
    Skill skill;

public:
    Task() {
        id = 0;
        duration = 0;
        startTime = 0;
        dependencies = nullptr;
        dependencyCount = 0;
    }
    Task(int id, int duration, int startTime, int* dependencies, int dependencyCount, Skill skill) {
        this->id = id;
        this->duration = duration;
        this->startTime = startTime;
        this->dependencies = dependencies;
        this->dependencyCount = dependencyCount;
        this->skill = skill;
    }
    int getId() {
        return id;
    }
    int getDuration() {
        return duration;
    }
    int getStartTime() {
        return startTime;
    }
    int* getDependencies() {
        return dependencies;
    }
    int getDependencyCount() {
        return dependencyCount;
    }
    Skill getSkill() {
        return skill;
    }
    void setId(int id) {
        this->id = id;
    }
    void setDuration(int duration) {
        this->duration = duration;
    }
    void setStartTime(int startTime) {
        this->startTime = startTime;
    }
    void setDependencies(int* dependencies) {
        this->dependencies = dependencies;
    }
    void setDependencyCount(int dependencyCount) {
        this->dependencyCount = dependencyCount;
    }
    void setSkill(Skill skill) {
        this->skill = skill;
    }
};

// Class for Project
class Project {
private:
    int id;
    int duration;
    Task* tasks;
    int taskCount;
    Resource* resources;
    int resourceCount;

public:
    Project() {
        id = 0;
        duration = 0;
        tasks = nullptr;
        taskCount = 0;
        resources = nullptr;
        resourceCount = 0;
    }
    Project(int id, int duration, Task* tasks, int taskCount, Resource* resources, int resourceCount) {
        this->id = id;
        this->duration = duration;
        this->tasks = tasks;
        this->taskCount = taskCount;
        this->resources = resources;
        this->resourceCount = resourceCount;
    }
    int getId() {
        return id;
    }
    int getDuration() {
        return duration;
    }
    Task* getTasks() {
        return tasks;
    }
    int getTaskCount() {
        return taskCount;
    }
    Resource* getResources() {
        return resources;
    }
    int getResourceCount() {
        return resourceCount;
    }
    void setId(int id) {
        this->id = id;
    }
    void setDuration(int duration) {
        this->duration = duration;
    }
    void setTasks(Task* tasks) {
        this->tasks = tasks;
    }
    void setTaskCount(int taskCount) {
        this->taskCount = taskCount;
    }
    void setResources(Resource* resources) {
        this->resources = resources;
    }
    void setResourceCount(int resourceCount) {
        this->resourceCount = resourceCount;
    }
};

// Function to add resources to the project
void addResources(Project& project) {
    int resourceCount = 0;
    cout << "Enter the number of resources: ";
    cin >> resourceCount;
    Resource* resources = new Resource[resourceCount];
    for (int i = 0; i < resourceCount; i++) {
        int id = 0;
        int availability = 0;
        int skillId = 0;
        int proficiency = 0;
        cout << "Enter the id of resource " << i + 1 << ": ";
        cin >> id;
        cout << "Enter the availability of resource " << i + 1 << ": ";
        cin >> availability;
        cout << "Enter the skill id of resource " << i + 1 << ": ";
        cin >> skillId;
        cout << "Enter the proficiency of resource " << i + 1 << ": ";
        cin >> proficiency;
        Skill skill(skillId, proficiency);
        Resource resource(id, availability, skill);
        resources[i] = resource;
    }
    project.setResources(resources);
    project.setResourceCount(resourceCount);
}

// Function to add tasks to the project
void addTasks(Project& project) {
    int taskCount = 0;
    cout << "Enter the number of tasks: ";
    cin >> taskCount;
    Task* tasks = new Task[taskCount];
    for (int i = 0; i < taskCount; i++) {
        int id = 0;
        int duration = 0;
        int startTime = 0;
        int dependencyCount = 0;
        int* dependencies = nullptr;
        int skillId = 0;
        int proficiency = 0;
        cout << "Enter the id of task " << i + 1 << ": ";
        cin >> id;
        cout << "Enter the duration of task " << i + 1 << ": ";
        cin >> duration;
        cout << "Enter the start time of task " << i + 1 << ": ";
        cin >> startTime;
        cout << "Enter the number of dependencies of task " << i + 1 << ": ";
        cin >> dependencyCount;
        if (dependencyCount > 0) {
            dependencies = new int[dependencyCount];
            cout << "Enter the dependencies of task " << i + 1 << ": ";
            for (int j = 0; j < dependencyCount; j++) {
                cin >> dependencies[j];
            }
        }
        cout << "Enter the skill id of task " << i + 1 << ": ";
        cin >> skillId;
        cout << "Enter the proficiency of task " << i + 1 << ": ";
        cin >> proficiency;
        Skill skill(skillId, proficiency);
        Task task(id, duration, startTime, dependencies, dependencyCount, skill);
        tasks[i] = task;
    }
    project.setTasks(tasks);
    project.setTaskCount(taskCount);
}

// Function to modify the duration of all tasks in the project
void setTaskDuration(Project& project) {
    int duration = 0;
    cout << "Enter the duration of all tasks: ";
    cin >> duration;
    for (int i = 0; i < project.getTaskCount(); i++) {
        project.getTasks()[i].setDuration(duration);
    }
}

// Function to change the duration of a specific task
void set_nth_TaskDuration(Project& project) {
    int n = 0;
    cout << "Enter the task number: ";
    cin >> n;
    int duration = 0;
    cout << "Enter the duration of task " << n << ": ";
    cin >> duration;
    project.getTasks()[n - 1].setDuration(duration);
}

// Function to display the dependencies of all tasks
void printTaskDependencyList(Project& project) {
    for (int i = 0; i < project.getTaskCount(); i++) {
        cout << "Task " << project.getTasks()[i].getId() << " depends on: ";
        for (int j = 0; j < project.getTasks()[i].getDependencyCount(); j++) {
            cout << project.getTasks()[i].getDependencies()[j] << " ";
        }
        cout << endl;
    }
}

// Function to compute and display the project's schedule and print the completion time
void calculateBasicSchedule(Project& project) {
    int* completionTimes = new int[project.getTaskCount()];
    for (int i = 0; i < project.getTaskCount(); i++) {
        completionTimes[i] = project.getTasks()[i].getDuration();
        for (int j = 0; j < project.getTasks()[i].getDependencyCount(); j++) {
                completionTimes[i] = completionTimes[project.getTasks()[i].getDependencies()[j] - 1] + project.getTasks()[i].getDuration();
            if (completionTimes[i] < completionTimes[project.getTasks()[i].getDependencies()[j] - 1] + project.getTasks()[i].getDuration()) {
            }
        }
    }
    cout << "Task\tStart\tEnd" << endl;
    for (int i = 0; i < project.getTaskCount(); i++) {
        cout << project.getTasks()[i].getId() << "\t" << completionTimes[i] - project.getTasks()[i].getDuration() << "\t" << completionTimes[i] << endl;
    }
    cout << "Project Completion Time: " << completionTimes[project.getTaskCount() - 1] << endl;
}

// Function to identify and return the critical tasks while displaying them
void printCriticalTasks(Project& project) {
    int* completionTimes = new int[project.getTaskCount()];
    for (int i = 0; i < project.getTaskCount(); i++) {
        completionTimes[i] = project.getTasks()[i].getDuration();
        for (int j = 0; j < project.getTasks()[i].getDependencyCount(); j++) {
            if (completionTimes[i] < completionTimes[project.getTasks()[i].getDependencies()[j] - 1] + project.getTasks()[i].getDuration()) {
                completionTimes[i] = completionTimes[project.getTasks()[i].getDependencies()[j] - 1] + project.getTasks()[i].getDuration();
            }
        }
    }
    cout << "Critical Tasks: ";
    for (int i = 0; i < project.getTaskCount(); i++) {
        if (completionTimes[i] == completionTimes[project.getTaskCount() - 1]) {
            cout << project.getTasks()[i].getId() << " ";
        }
    }
    cout << endl;
}

// Function to calculate the project's completion time considering resource availability, allowing tasks to start based on resource availability
void completionTimeWithResources(Project& project) {
    int* completionTimes = new int[project.getTaskCount()];
    for (int i = 0; i < project.getTaskCount(); i++) {
        completionTimes[i] = project.getTasks()[i].getDuration();
        for (int j = 0; j < project.getTasks()[i].getDependencyCount(); j++) {
            if (completionTimes[i] < completionTimes[project.getTasks()[i].getDependencies()[j] - 1] + project.getTasks()[i].getDuration()) {
                completionTimes[i] = completionTimes[project.getTasks()[i].getDependencies()[j] - 1] + project.getTasks()[i].getDuration();
            }
        }
    }
    cout << "Task\tStart\tEnd" << endl;
    for (int i = 0; i < project.getTaskCount(); i++) {
        cout << project.getTasks()[i].getId() << "\t" << completionTimes[i] - project.getTasks()[i].getDuration() << "\t" << completionTimes[i] << endl;
    }
    cout << "Project Completion Time: " << completionTimes[project.getTaskCount() - 1] << endl;
}

// Function to compute the project's completion time, taking into account resource availability and their proficiency levels, enabling tasks to commence accordingly
void completionTimeWithResourceProficiency(Project& project) {
    int* completionTimes = new int[project.getTaskCount()];
    for (int i = 0; i < project.getTaskCount(); i++) {
        completionTimes[i] = project.getTasks()[i].getDuration();
        for (int j = 0; j < project.getTasks()[i].getDependencyCount(); j++) {
            if (completionTimes[i] < completionTimes[project.getTasks()[i].getDependencies()[j] - 1] + project.getTasks()[i].getDuration()) {
                completionTimes[i] = completionTimes[project.getTasks()[i].getDependencies()[j] - 1] + project.getTasks()[i].getDuration();
            }
        }
    }
    cout << "Task\tStart\tEnd" << endl;
    for (int i = 0; i < project.getTaskCount(); i++) {
        cout << project.getTasks()[i].getId() << "\t" << completionTimes[i] - project.getTasks()[i].getDuration() << "\t" << completionTimes[i] << endl;
    }
    cout << "Project Completion Time: " << completionTimes[project.getTaskCount() - 1] << endl;
}

// Function to display the menu
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

int main() {
    Project project;
    int choice = 0;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addResources(project);
            break;
        case 2:
            addTasks(project);
            break;
        case 3:
            setTaskDuration(project);
            break;
        case 4:
            set_nth_TaskDuration(project);
            break;
        case 5:
            printTaskDependencyList(project);
            break;
        case 6:
            calculateBasicSchedule(project);
            break;
        case 7:
            printCriticalTasks(project);
            break;
        case 8:
            completionTimeWithResources(project);
            break;
        case 9:
            completionTimeWithResourceProficiency(project);
            break;
        case 10:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 10);
    return 0;
}

// #include <iostream>
// #include <string>

// using namespace std;

// // Define a Skill class to represent skills and proficiency levels
// class Skill
// {
// public:
//     string id;
//     int proficiencyLevel;
//     Skill *next;

//     Skill(string _id, int _proficiencyLevel) : id(_id), proficiencyLevel(_proficiencyLevel), next(nullptr) {}
// };

// // Define a Resource class to represent resources (people or things)
// class Resource
// {
// public:
//     string id;
//     Skill *skills;
//     int availabilityStart;
//     int availabilityEnd;
//     Resource *next;

//     Resource(string _id, int _availabilityStart, int _availabilityEnd) : id(_id), skills(nullptr), availabilityStart(_availabilityStart), availabilityEnd(_availabilityEnd), next(nullptr) {}

//     void addSkill(string skillId, int proficiencyLevel)
//     {
//         Skill *newSkill = new Skill(skillId, proficiencyLevel);
//         if (!skills)
//         {
//             skills = newSkill;
//         }
//         else
//         {
//             Skill *current = skills;
//             while (current->next)
//             {
//                 current = current->next;
//             }
//             current->next = newSkill;
//         }
//     }
// };

// // Define a Task class to represent tasks in the project
// class Task
// {
// public:
//     string id;
//     int duration;
//     int startTime;
//     string requiredSkill;
//     Task *next;

//     Task(string _id, int _duration, string _requiredSkill) : id(_id), duration(_duration), startTime(0), requiredSkill(_requiredSkill), next(nullptr) {}
// };

// // Define a Project class to represent the project
// class Project
// {
// public:
//     string id;
//     int totalDuration;
//     Task *tasks;
//     Resource *resources;

//     Project(string _id, int _totalDuration) : id(_id), totalDuration(_totalDuration), tasks(nullptr), resources(nullptr) {}

//     void addResource(string resourceId, int availabilityStart, int availabilityEnd)
//     {
//         Resource *newResource = new Resource(resourceId, availabilityStart, availabilityEnd);
//         if (!resources)
//         {
//             resources = newResource;
//         }
//         else
//         {
//             Resource *current = resources;
//             while (current->next)
//             {
//                 current = current->next;
//             }
//             current->next = newResource;
//         }
//     }

//     void addSkillToResource(string resourceId, string skillId, int proficiencyLevel)
//     {
//         Resource *currentResource = resources;
//         while (currentResource)
//         {
//             if (currentResource->id == resourceId)
//             {
//                 currentResource->addSkill(skillId, proficiencyLevel);
//                 break;
//             }
//             currentResource = currentResource->next;
//         }
//     }

//     void addTask(string taskId, int duration, string requiredSkill)
//     {
//         Task *newTask = new Task(taskId, duration, requiredSkill);
//         if (!tasks)
//         {
//             tasks = newTask;
//         }
//         else
//         {
//             Task *current = tasks;
//             while (current->next)
//             {
//                 current = current->next;
//             }
//             current->next = newTask;
//         }
//     }

//     void printResourceInfo()
//     {
//         Resource *currentResource = resources;
//         while (currentResource)
//         {
//             cout << "Resource ID: " << currentResource->id << endl;
//             cout << "Availability: " << currentResource->availabilityStart << " - " << currentResource->availabilityEnd << endl;
//             cout << "Skills: ";
//             Skill *currentSkill = currentResource->skills;
//             while (currentSkill)
//             {
//                 cout << currentSkill->id << " (Proficiency: " << currentSkill->proficiencyLevel << "), ";
//                 currentSkill = currentSkill->next;
//             }
//             cout << endl
//                  << endl;
//             currentResource = currentResource->next;
//         }
//     }
// };

// int main()
// {
//     Project project("Project1", 30); // Create a project with a total duration of 30 days

//     // Add resources to the project
//     project.addResource("Resource1", 8, 17);
//     project.addResource("Resource2", 9, 18);

//     // Add skills to resources
//     project.addSkillToResource("Resource1", "Programming", 3);
//     project.addSkillToResource("Resource2", "Design", 2);

//     // Add tasks to the project
//     project.addTask("Task1", 5, "Programming");
//     project.addTask("Task2", 4, "Design");

//     // Print resource information
//     project.printResourceInfo();

//     return 0;
// }
