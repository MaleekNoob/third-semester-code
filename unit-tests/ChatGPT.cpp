#include <iostream>
#include <string>

using namespace std;

// Define a structure for a tree node
struct Node
{
    string name;
    string path;
    string type; // "file" or "directory"
    Node *children;

    // Constructor for creating a new node
    Node(string n, string p, string t) : name(n), path(p), type(t), children(nullptr) {}
};

// Function to create a new directory in the tree
Node *createDirectory(Node *parent, string dirName)
{
    string dirPath = parent->path + "/" + dirName;
    Node *newDir = new Node(dirName, dirPath, "directory");
    if (parent->children == nullptr)
    {
        parent->children = newDir;
    }
    else
    {
        Node *current = parent->children;
        while (current->children != nullptr)
        {
            current = current->children;
        }
        current->children = newDir;
    }
    return newDir;
}

// Function to create a new file in the tree
Node *createFile(Node *parent, string fileName, string fileType)
{
    string filePath = parent->path + "/" + fileName + "." + fileType;
    Node *newFile = new Node(fileName, filePath, "file");
    if (parent->children == nullptr)
    {
        parent->children = newFile;
    }
    else
    {
        Node *current = parent->children;
        while (current->children != nullptr)
        {
            current = current->children;
        }
        current->children = newFile;
    }
    return newFile;
}

// Function to display the tree
void displayTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->name << endl;
    displayTree(root->children);
}

// Function to delete the tree
void deleteTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    deleteTree(root->children);
    delete root;
}

int main()
{
    // Create the root directory
    Node *root = new Node("Root", "/", "directory");

    // Create directories and files
    Node *patientDataDir = createDirectory(root, "PatientData");
    Node *logsDir = createDirectory(root, "Logs");

    createFile(patientDataDir, "Patient1", "txt");
    createFile(patientDataDir, "Patient2", "pdf");
    createFile(logsDir, "Log1", "txt");

    // Display the directory tree
    cout << "File Directory Tree:" << endl;
    displayTree(root);

    // Memory cleanup (free allocated memory)
    deleteTree(root);

    return 0;
}
