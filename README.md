﻿# third-semester-code
# Project Scheduler

## Objective
The objective of this project is to create a project scheduler that efficiently plans and manages tasks, resources, and timelines, ensuring project completion within the set timeframe. This scheduler takes into account task details, resource allocation, and skill proficiency to optimize project completion timelines.

## Assignment Statement
In the realm of project management, scheduling is a fundamental task that involves determining the timeline for project completion. This project enhances traditional scheduling methods, such as the Critical Path Method (CPM), by considering not only task-related information but also the availability of resources and their skill sets.

### Key Structures
1. **Task**: Each task is characterized by its unique identifier (id), duration, start time, dependencies on other tasks, and the skill required to execute it (skill_id).

2. **Project**: A project consists of a unique identifier (id), duration, and a collection of tasks.

3. **Skill**: Skills are associated with specific identifiers (id) and proficiency levels.

4. **Resource**: Resources are defined by their identifiers (id), availability, and the skill they possess.

### Functions to Implement
- `addResources()`: Add resources to the project, along with their skill and proficiency.
The addResources() function associates resources with tasks in the project. It prompts the user to input resource details, including an identifier, availability, skill, and skill proficiency. Resources are then linked to the appropriate tasks, ensuring efficient project execution. This function is vital for optimizing resource allocation within the project.


- `addTasks()`: Add tasks to the project, and provide relevant information.
The addTasks() function allows the user to input task details, including an identifier and duration. Users can specify task dependencies, if any, to build a logical sequence of tasks. The function then calculates Early Start (ES) and Early Finish (EF) times, ensuring proper scheduling within the project.

  
- `setTaskDuration()`: Modify the duration of all tasks in the project.
The setTaskDuration() function enables users to modify the duration of individual tasks in the project. It iterates through the tasks, allowing users to update task durations, which can be essential for adapting the project timeline as needed.
- `set_nth_TaskDuration()`: Change the duration of a specific task.
- `printTaskDependencyList()`: Display the dependencies of all tasks.
- `calculateBasicSchedule()`: Utilize the Critical Path Method to compute and display the project's schedule and print the completion time.
- `printCriticalTasks()`: Identify and return the critical tasks while displaying them. The sum of their durations should match the project's completion time.
- `completionTimeWithResources()`: Calculate the project's completion time considering resource availability, allowing tasks to start based on resource availability.
- `completionTimeWithResourceProficiency()`: Compute the project's completion time, taking into account resource availability and proficiency levels, enabling tasks to commence accordingly.
