#include <iostream>
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
    T* head;

public:
    Stack() {
        head = nullptr;
    }

    void push(T data) {
        // code
    }

    T& pop() {
        // code
    }

    void display() {
        // code
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

    // stack<Weight*> BFS()

};

int main() {

    Graph graph(5);
    graph.makeEdge(0, 3, 0.1);
    graph.makeEdge(0, 4, 0.1);
    graph.makeEdge(0, 1, 0.1);
    graph.makeEdge(1, 4, 0.1);
    graph.makeEdge(1, 2, 0.1);
    graph.makeEdge(2, 3, 0.1);
    graph.makeEdge(3, 4, 0.1);
    graph.makeEdge(4, 1, 0.1);
    graph.displayGraph();

    return 0;
}