#include <iostream>
#include <iomanip>

const int MAX_VERTICES = 100; // Adjust the maximum number of vertices as needed

class WeightedGraph
{
private:
    int V;           // Number of vertices
    int **adjMatrix; // Adjacency matrix: stores weights

public:
    WeightedGraph(int vertices)
    {
        V = vertices;

        // Dynamically allocate memory for the adjacency matrix
        adjMatrix = new int *[V];
        for (int i = 0; i < V; ++i)
        {
            adjMatrix[i] = new int[V];
            // Initialize all weights to -1 (assuming -1 is not a valid weight)
            for (int j = 0; j < V; ++j)
            {
                adjMatrix[i][j] = -1;
            }
        }
    }

    // Add an edge to the graph
    void addEdge(int u, int v, int weight)
    {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // Assuming the graph is undirected
    }

    // Display the adjacency matrix representation of the graph
    void displayGraph()
    {
        // display in form of matrix
        std::cout << "Adjacency Matrix:" << std::endl;
        std::cout << "    " << " ";
        for (int i = 0; i < V; ++i)
        {
            std::cout << "   " << i;
        }
        std::cout << std::endl;
        for (int i = 0; i < V; ++i)
        {
            std::cout << "   " << i;
            for (int j = 0; j < V; ++j)
            {
                std::cout << "   " << adjMatrix[i][j];
            }
            std::cout << std::endl;
        }
    }

    ~WeightedGraph()
    {
        // Deallocate memory for the adjacency matrix
        for (int i = 0; i < V; ++i)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main()
{
    WeightedGraph graph(4); // Create a graph with 4 vertices

    // Add edges with weights
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 3);

    // Display the graph
    graph.displayGraph();

    return 0;
}
