#include "Graph.h"

int main()
{
    int choice = 0;
    int vertices = 0;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    Graph graph(vertices);

    while (true)
    {
        cout << "1. Print Graph\n2. Make Direct Edge\n3. Make Undirect Edge\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            graph.printGraph();
            break;
        }

        case 2:
        {
            int src = 0;
            int dest = 0;
            cout << "Enter source: ";
            cin >> src;
            cout << "Enter destination: ";
            cin >> dest;
            graph.addEdgeDirected(src, dest);
            break;
        }

        case 3:
        {
            int src = 0;
            int dest = 0;
            cout << "Enter source: ";
            cin >> src;
            cout << "Enter destination: ";
            cin >> dest;
            graph.addEdgeUndirected(src, dest);
            break;
        }

        case 4:
        {
            return 0;
        }

        default:
        {
            cout << "Invalid choice!" << endl;
            break;
        }
        }
    }

    return 0;
}