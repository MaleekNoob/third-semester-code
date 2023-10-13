# third-semester-code
# Project Scheduler

## Objective
The objective of this project is to create a project scheduler that efficiently plans and manages tasks, resources, and timelines, ensuring project completion within the set timeframe. This scheduler takes into account task details, resource allocation, and skill proficiency to optimize project completion timelines.

## Assignment Statement
In the realm of Project Management, scheduling is a fundamental task that involves determining the timeline for project completion. This project enhances traditional scheduling methods, such as the Critical Path Method (CPM), by considering not only task-related information but also the availability of resources and their skill sets.

### Key Structures
1. **Task**: Each task is characterized by its unique identifier (id), duration, start time, dependencies on other tasks, and the skill required to execute it (skill_id).

2. **Project**: A project consists of a unique identifier (id), duration, and a collection of tasks.

3. **Skill**: Skills are associated with specific identifiers (id) and proficiency levels.

4. **Resource**: Resources are defined by their identifiers (id), availability, and the skill they possess.

### Functions to Implement
- `addResources()`: Add resources to the project, along with their skill and proficiency.
  Function Workflow
The function iterates through the list of tasks in the project, starting from the first task and moving through the list.
For each task, it prompts the user to enter specific details for the associated resource, including:
Resource Identifier: A unique identifier for the resource.
Resource Availability: The availability of the resource, which indicates when the resource can be assigned to tasks.
Resource Skill Identifier: The skill required for the task, matching the skill set of the resource.
Resource Skill Proficiency: The proficiency level of the resource in the required skill.
The function creates a Skill object with the resource's skill identifier and proficiency level.
It then creates a Resource object with the resource identifier, availability, and the skill created in the previous step.
The resource is associated with the task using the setResource() method.
The isResourceAdded flag for the task is set to true to indicate that a resource has been successfully added to the task.
The function moves on to the next task in the list and repeats the resource assignment process.
- `addTasks()`: Add tasks to the project, and provide relevant information.
- `setTaskDuration()`: Modify the duration of all tasks in the project.
- `set_nth_TaskDuration()`: Change the duration of a specific task.
- `printTaskDependencyList()`: Display the dependencies of all tasks.
- `calculateBasicSchedule()`: Utilize the Critical Path Method to compute and display the project's schedule and print the completion time.
- `printCriticalTasks()`: Identify and return the critical tasks while displaying them. The sum of their durations should match the project's completion time.
- `completionTimeWithResources()`: Calculate the project's completion time considering resource availability, allowing tasks to start based on resource availability.
- `completionTimeWithResourceProficiency()`: Compute the project's completion time, taking into account resource availability and their proficiency levels, enabling tasks to commence accordingly.
