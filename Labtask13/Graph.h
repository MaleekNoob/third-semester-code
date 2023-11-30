#include <iostream>
using namespace std;

struct Vertex
{
    int vertex;
    float weight;
    Vertex *next;
};

class LinkedList
{
    Vertex *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void addNode(int vertex)
    {
        Vertex *newNode = new Vertex;
        newNode->vertex = vertex;
        newNode->next = head;
        head = newNode;

        cout << endl
             << "Enter weight: ";
        cin >> newNode->weight;
    }

    void printList()
    {
        Vertex *temp = head;
        while (temp)
        {
            cout << " " << temp->vertex << "(" << temp->weight << ")";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Graph
{
    int vertices;
    LinkedList *adjList;

public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        adjList = new LinkedList[vertices];
    }

    // For directed graph
    void addEdgeDirected(int src, int dest)
    {
        adjList[src].addNode(dest);
    }

    // For undirected graph
    void addEdgeUndirected(int src, int dest)
    {
        adjList[src].addNode(dest);
        adjList[dest].addNode(src);
    }

    void printGraph()
    {
        int v;
        for (v = 0; v < vertices; ++v)
        {
            cout << "Vertex " << v << " is linked to";
            adjList[v].printList();
        }
    }
};