#include <iostream>
#include <limits>
using namespace std;

class Weight {
    int src;
    int dest;
    float weight;

    public:
    Weight* next;

    Weight(int src, int dest, float weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
        next = nullptr;
    }

    int getDest() {
        return dest;
    }

    int getSrc() {
        return src;
    }

    float getWeight() {
        return weight;
    }

    void display() {
        cout << "(Node: " << dest << ", Weight: " << weight << ")";
    }

};

class List {
    private:
    Weight* head;

    public:
    List() {
        head = nullptr;
    }

    void insert(int src, int dest, float weight) {
        Weight* newWeight = new Weight(src, dest, weight);
        if (empty()) {
            head = newWeight;
            return;
        }
        Weight* traverse = head;
        while (traverse->next != nullptr) {
            traverse = traverse->next;
        }
        traverse->next = newWeight;
    }

    void remove(int src, int dest, float weight) {
        if (empty()) {
            cout << endl << "List is empty";
            return;
        }

        if (head->getDest() == dest) {
            Weight* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return;
        }

        Weight* traverse = head;
        while (traverse->next != nullptr && traverse->next->getDest() != dest)
        {
            traverse = traverse->next;
        }

        if (traverse->next == nullptr) {
            cout << endl << "Value not found";
            return;
        }

        Weight* temp = traverse->next;
        traverse->next = traverse->next->next;
        temp->next = nullptr;
        delete temp;
    }

    bool empty() {
        return (head == nullptr);
    }

    void display() {
        Weight* traverse = head;
        cout << endl;
        while (traverse != nullptr) {
            traverse->display();
            cout << " -> ";
            traverse = traverse->next;
        }
        return;
    }

    Weight* getHead() {
        return head;
    }

};

template <typename T>
class Stack {
    struct Node
    {
        T data;
        Node* next;

        Node(T &data) {
            this->data = data;
            next = nullptr;
        }
    };
    Node* topNode;

    public:
    Stack() {
        topNode = nullptr;
    }

    void push(T data) {
        Node *newNode = new Node(data);
        newNode->next = topNode;
        topNode = newNode;
    }

    T& pop()
    {
        if (!empty())
        {
            Node *temp = topNode;
            topNode = topNode->next;
            return temp->data;
        }
        cout << endl << "Stack is empty";
        throw underflow_error("Stack is empty");
    }

    T &top()
    {
        if (!empty())
        {
            return topNode->data;
        }        
    }

    bool empty() {
        return (topNode == nullptr);
    }

    void display() {
        Node* temp = topNode;
        while (temp != nullptr) {
            cout << endl << temp->data;
            temp = temp->next;
        }
    }
};

class Queue {
    struct Node
    {
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = nullptr;
        }
    };
    Node* frontNode;
    Node* rearNode;

    public:
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    void enqueue(int data) {
        Node *newNode = new Node(data);
        if (empty()) {
            frontNode = newNode;
            rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
    }

    int dequeue()
    {
        if (!empty())
        {
            Node *temp = frontNode;
            frontNode = frontNode->next;
            int data = temp->data;
            temp->next = nullptr;
            delete temp;
            return data;
        }
        cout << endl << "Queue is empty";
        throw underflow_error("Queue is empty");
    }

    int front()
    {
        if (!empty())
        {
            return frontNode->data;
        }        
    }

    bool empty() {
        return (frontNode == nullptr);
    }

    void display() {
        Node* temp = frontNode;
        while (temp != nullptr) {
            cout << endl << temp->data;
            temp = temp->next;
        }
    }
};

class PriorityQueue
{
private:
    struct Node
    {
        int vertex;
        float distance;

        Node() : vertex(0), distance(0.0) {}

        Node(int v, float d) : vertex(v), distance(d) {}
    };

    Node *array;
    int capacity;
    int size;

public:
    PriorityQueue(int capacity) : capacity(capacity), size(0)
    {
        array = new Node[capacity];
    }

    void push(int vertex, float distance)
    {
        if (size == capacity)
        {
            cout << endl
                 << "Priority Queue is full";
            return;
        }

        int i = size++;
        array[i] = Node(vertex, distance);

        // Maintain heap property
        while (i > 0 && array[(i - 1) / 2].distance > array[i].distance)
        {
            swap(array[i], array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    Node pop()
    {
        if (empty())
        {
            cout << endl
                 << "Priority Queue is empty";
            throw underflow_error("Priority Queue is empty");
        }

        Node root = array[0];
        array[0] = array[--size];

        // Maintain heap property
        int i = 0;
        while (true)
        {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && array[left].distance < array[smallest].distance)
                smallest = left;

            if (right < size && array[right].distance < array[smallest].distance)
                smallest = right;

            if (smallest != i)
            {
                swap(array[i], array[smallest]);
                i = smallest;
            }
            else
            {
                break;
            }
        }

        return root;
    }

    bool empty() const
    {
        return size == 0;
    }
};

class Graph {
    private:
    List* graph;
    int numVertices;

    public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        graph = new List[numVertices];
    }

    void displayVertices() {
        cout << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << " ";
        }
    }

    bool checkVertexInList(int vertex) {
        for (int i = 0; i < numVertices; i++)
        {
            if (i == vertex) {
                return true;
            }
        }
        return false;
    }
    
    void vertexHandling(int &vertex) {
        while (!checkVertexInList(vertex)) {
            cout << endl << "Vertex not in the list\nPlease Enter valid source: ";
            cin >> vertex;
        }
    }

    void makeEdge(int src, int dest, float weight) {
        graph[src].insert(src, dest, weight);
    }

    void userMakeEdge() {
        int src, dest;
        displayVertices();
        cout << endl << "Enter source: ";
        cin >> src;
        vertexHandling(src);
        cout << endl << "Enter destination: ";
        cin >> dest;
        vertexHandling(dest);
        makeEdge(src, dest, 0.1);
    }

    void displayNeighbours(int vertex) {
        cout << endl << "Vertex " << vertex << ": ";
        vertexHandling(vertex);
        graph[vertex].display();
    }

    void displayGraph() {
        for (int i = 0; i < numVertices; i++) {
            displayNeighbours(i);
        }
    }

    void BFS(int src_vertex, int dest_vertex) {
        Queue queue;
        bool visited[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }
        queue.enqueue(src_vertex);
        visited[src_vertex] = true;
        while (!queue.empty()) {
            int vertex = queue.dequeue();
            cout << vertex << " ";
            if (vertex == dest_vertex) {
                cout << endl << "Path found";
                return;
            }
            Weight* traverse = graph[vertex].getHead();
            while (traverse != nullptr) {
                if (!visited[traverse->getDest()]) {
                    queue.enqueue(traverse->getDest());
                    visited[traverse->getDest()] = true;
                }
                traverse = traverse->next;
            }
        }
        cout << endl << "Path not found";
    
    }

    void Dijkstra(int src_vertex, int dest_vertex)
    {
        float *distance = new float[numVertices];
        int *parent = new int[numVertices];

        for (int i = 0; i < numVertices; ++i)
        {
            distance[i] = numeric_limits<float>::infinity();
            parent[i] = -1;
        }

        distance[src_vertex] = 0;

        PriorityQueue pq(numVertices);
        pq.push(src_vertex, 0);

        while (!pq.empty())
        {
            int u = pq.pop().vertex;

            Weight *traverse = graph[u].getHead();
            while (traverse != nullptr)
            {
                int v = traverse->getDest();
                float w = traverse->getWeight();

                if (distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                    parent[v] = u;
                    pq.push(v, distance[v]);
                }

                traverse = traverse->next;
            }
        }

        cout << endl << "Shortest Path from " << src_vertex << " to " << dest_vertex << ": ";
        printShortestPath(parent, dest_vertex);
    }

    void printShortestPath(int *parent, int dest_vertex)
    {
        if (parent[dest_vertex] == -1)
        {
            cout << endl
                 << "No path exists";
            return;
        }

        int current = dest_vertex;
        Stack<int> pathStack;
        while (current != -1)
        {
            pathStack.push(current);
            current = parent[current];
        }

        while (!pathStack.empty())
        {
            cout << pathStack.pop() << " ";
        }
    }
};

int main() {

    Graph graph(5);
    graph.makeEdge(0, 3, 0.7);
    graph.makeEdge(0, 4, 0.4);
    graph.makeEdge(0, 1, 0.35);
    graph.makeEdge(1, 4, 0.22);
    graph.makeEdge(1, 2, 0.13);
    graph.makeEdge(2, 3, 0.91);
    graph.makeEdge(3, 4, 0.18);
    graph.makeEdge(4, 1, 0.51);
    graph.displayGraph();
    graph.Dijkstra(0, 2);

    return 0;
}