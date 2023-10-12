#include "Queue.h"

class Task
{
public:
    int executionTime;
    char id;
};

void roundRobin(Queue<Task> task_queue, int timeSlice = 1)
{
    while (!task_queue.isEmpty())
    {
        Task task = task_queue.peek();
        task.executionTime -= timeSlice;
        task_queue.dequeue();
        if (task.executionTime > 0)
        {
            cout << "Task " << task.id << " executed for " << timeSlice << " seconds." << endl;
            task_queue.enqueue(task);
        }
        else
        {
            cout << "Task " << task.id << " executed for " << task.executionTime << " seconds." << endl;
        }
    }
}