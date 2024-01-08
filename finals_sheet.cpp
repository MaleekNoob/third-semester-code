#include <iostream>
#include <vector>
#include <limits>
using namespace std;

/* Linked List */

struct Node
{
    int data;
    int weight;
    Node *next;

    Node(int d, int w) : data(d), weight(w), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    void addNode(int data, int weight)
    {
        Node *newNode = new Node(data, weight);
        newNode->next = head;
        head = newNode;
    }
};

/* Binary Min Heap */

class BinaryMinHeap
{
private:
    struct HeapNode
    {
        int vertex;
        int distance;

        HeapNode(int v, int d) : vertex(v), distance(d) {}
    };

    struct Node
    {
        HeapNode data;
        Node *left;
        Node *right;

        Node(int v, int d) : data(v, d), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *insert(Node *root, int vertex, int distance)
    {
        if (root == nullptr)
        {
            return new Node(vertex, distance);
        }

        if (distance < root->data.distance)
        {
            root->left = insert(root->left, vertex, distance);
        }
        else
        {
            root->right = insert(root->right, vertex, distance);
        }

        return root;
    }

    Node *extractMin(Node *root, HeapNode &minValue)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->left == nullptr)
        {
            minValue = root->data;
            Node *temp = root->right;
            delete root;
            return temp;
        }

        root->left = extractMin(root->left, minValue);

        return root;
    }

public:
    BinaryMinHeap() : root(nullptr) {}

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void insert(int vertex, int distance)
    {
        root = insert(root, vertex, distance);
    }

    HeapNode extractMin()
    {
        if (isEmpty())
        {
            return HeapNode(-1, numeric_limits<int>::max());
        }

        HeapNode minValue(1, 1);
        root = extractMin(root, minValue);

        return minValue;
    }
};

/* Graph using AdjList */

class WeightedGraph
{
private:
    int V;
    LinkedList *adjList;

public:
    WeightedGraph(int vertices) : V(vertices)
    {
        adjList = new LinkedList[vertices];
    }

    void addEdge(int src, int dest, int weight)
    {
        adjList[src].addNode(dest, weight);
        adjList[dest].addNode(src, weight);
    }

    void displayGraph()
    {
        for (int i = 0; i < V; ++i)
        {
            Node *current = adjList[i].head;
            cout << "Vertex " << i << " is connected to: ";
            while (current)
            {
                cout << "(" << current->data << ", " << current->weight << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }

    vector<int> dijkstra(int source)
    {
        vector<int> distances(V, numeric_limits<int>::max());
        distances[source] = 0;

        BinaryMinHeap minHeap;
        minHeap.insert(source, 0);

        while (!minHeap.isEmpty())
        {
            auto minValue = minHeap.extractMin();
            int current = minValue.vertex;
            int dist = minValue.distance;

            Node *neighbor = adjList[current].head;
            while (neighbor)
            {
                int neighborVertex = neighbor->data;
                int edgeWeight = neighbor->weight;

                if (dist + edgeWeight < distances[neighborVertex])
                {
                    distances[neighborVertex] = dist + edgeWeight;
                    minHeap.insert(neighborVertex, distances[neighborVertex]);
                }

                neighbor = neighbor->next;
            }
        }

        return distances;
    }

    ~WeightedGraph()
    {
        delete[] adjList;
    }
};

/* Queue */

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool empty() const
    {
        return front == nullptr;
    }

    void push(const T &value)
    {
        Node *newNode = new Node(value);

        if (empty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop()
    {
        if (empty())
        {
            cerr << "Cannot dequeue from an empty queue." << endl;
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
    }

    T getFront()
    {
        if (empty())
        {
            cerr << "Cannot get front from an empty queue." << endl;
            return T();
        }

        return front->data;
    }

    void display() const
    {
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Queue()
    {
        while (!empty())
        {
            pop();
        }
    }
};

/* AVL Tree */

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class AVL
{
private:
    TreeNode *root;

    void displayTreeData(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        displayTreeData(root->left);
        cout << root->data << " ";
        displayTreeData(root->right);
    }

    TreeNode *rightRotation(TreeNode *root)
    {
        if (root == nullptr || root->left == nullptr)
        {
            return root;
        }

        TreeNode *pivot = root->left;
        root->left = pivot->right;
        pivot->right = root;

        return pivot;
    }

    TreeNode *leftRotation(TreeNode *root)
    {
        if (root == nullptr || root->right == nullptr)
        {
            return root;
        }

        TreeNode *pivot = root->right;
        root->right = pivot->left;
        pivot->left = root;

        return pivot;
    }

    TreeNode *rightleftRotation(TreeNode *root)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    TreeNode *leftRightRotation(TreeNode *root)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + max(getHeight(root->right), getHeight(root->left));
    }

    TreeNode *insertData(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        else if (val > root->data)
        {
            root->right = insertData(root->right, val);

            if (getHeight(root->left) - getHeight(root->right) < 1)
            {
                // right heavy
                if (val > root->right->data)
                {
                    root = leftRotation(root);
                }
                else
                {
                    root = leftRightRotation(root);
                }
            }
        }
        else if (val < root->data)
        {
            root->left = insertData(root->left, val);

            if (getHeight(root->left) - getHeight(root->right) > 1)
            {
                // left heavy
                if (val < root->left->data)
                {
                    root = rightRotation(root);
                }
                else
                {
                    root = rightleftRotation(root);
                }
            }
        }

        return root;
    }

public:
    AVL()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        root = insertData(root, val);
    }

    void levelOrderDisplay()
    {
        if (root == nullptr)
        {
            return;
        }

        Queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty())
        {

            TreeNode *currentNode = q.getFront();
            q.pop();

            if (currentNode == nullptr)
            {
                cout << endl;

                if (!q.empty())
                {
                    q.push(nullptr);
                }

                continue;
            }

            cout << currentNode->data << " ";

            if (currentNode->left != nullptr)
            {
                q.push(currentNode->left);
            }

            if (currentNode->right != nullptr)
            {
                q.push(currentNode->right);
            }
        }
    }

    void display()
    {
        displayTreeData(root);
    }
};
