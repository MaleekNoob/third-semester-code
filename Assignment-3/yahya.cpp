#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a structure for a tree node
struct TreeNode
{
    string name;
    string path;
    string type;                 // "file" or "directory"
    vector<TreeNode *> children; // Vector to store multiple child nodes

    // Constructor for creating a new node
    TreeNode(string n, string p, string t) : name(n), path(p), type(t) {}
};

// Function to create a new directory in the tree
TreeNode *createDirectory(TreeNode *parent, string dirName)
{
    string dirPath = parent->path + "/" + dirName;
    TreeNode *newDir = new TreeNode(dirName, dirPath, "directory");
    parent->children.push_back(newDir);
    return newDir;
}

// Function to create a new file in the tree
TreeNode *createFile(TreeNode *parent, string fileName, string fileType)
{
    string filePath = parent->path + "/" + fileName + "." + fileType;
    TreeNode *newFile = new TreeNode(fileName, filePath, "file");
    parent->children.push_back(newFile);
    return newFile;
}

// Function to display the tree (pre-order traversal)
void displayTree(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << root->name << " (" << root->type << ") - " << root->path << endl;
        for (TreeNode *child : root->children)
        {
            displayTree(child);
        }
    }
}

// Function to delete the tree and free memory
void deleteTree(TreeNode *root)
{
    if (root != nullptr)
    {
        for (TreeNode *child : root->children)
        {
            deleteTree(child);
        }
        delete root;
    }
}

int main()
{
    // Create the root directory
    TreeNode *root = new TreeNode("Root", "/", "directory");

    // Create directories and files
    TreeNode *patientDataDir = createDirectory(root, "PatientData");
    TreeNode *logsDir = createDirectory(root, "Logs");

    createFile(patientDataDir, "Patient1", "txt");
    createFile(patientDataDir, "Patient2", "pdf");
    createFile(logsDir, "Log1", "txt");

    // Display the tree
    cout << "File Directory Tree:" << endl;
    displayTree(root);

    // Memory cleanup (free allocated memory)
    deleteTree(root);

    return 0;
}
