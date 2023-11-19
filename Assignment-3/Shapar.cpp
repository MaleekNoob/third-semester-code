/*
1. Implement a tree data structure to represent files and directories within the operaƟng system.
Each node in the tree should have the following aƩributes:
• Name: The name of the file or directory.
• Path: The full path to the file or directory.
• Type: IndicaƟon of whether the node is a directory or file.
• Children: A list of child nodes.
2. Develop a funcƟon to create a new directory within the tree. Users should be able to specify the
directory name.
3. Create a function to create new files within the tree, allowing users to specify the name, type
(e.g., txt, pdf), and complete path.
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    string path;
    string type;
    Node* children;
};

Node* createNode(string name, string path, string type) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->path = path;
    newNode->type = type;
    newNode->children = NULL;
    return newNode;
}

void createDirectory(Node* root, string name) {
    Node* newNode = createNode(name, root->path + "/" + name, "directory");
    root->children = newNode;
}

void createFile(Node* root, string name, string type) {
    Node* newNode = createNode(name, root->path + "/" + name, type);
    root->children = newNode;
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->name << endl;
    printTree(root->children);
}

int main() {
    Node* root = createNode("root", "root", "directory");
    createDirectory(root, "dir1");
    createDirectory(root, "dir2");
    createDirectory(root, "dir3");
    createFile(root, "file1", "txt");
    createFile(root, "file2", "pdf");
    createFile(root, "file3", "txt");
    createFile(root, "file4", "pdf");
    createFile(root, "file5", "txt");
    createFile(root, "file6", "pdf");
    createFile(root, "file7", "txt");
    createFile(root, "file8", "pdf");
    createFile(root, "file9", "txt");
    createFile(root, "file10", "pdf");
    createFile(root, "file11", "txt");
    createFile(root, "file12", "pdf");
    createFile(root, "file13", "txt");
    createFile(root, "file14", "pdf");
    createFile(root, "file15", "txt");
    createFile(root, "file16", "pdf");
    createFile(root, "file17", "txt");
    createFile(root, "file18", "pdf");
    createFile(root, "file19", "txt");
    createFile(root, "file20", "pdf");
    createFile(root, "file21", "txt");
    createFile(root, "file22", "pdf");
    createFile(root, "file23", "txt");
    createFile(root, "file24", "pdf");
    createFile(root, "file25", "txt");
    createFile(root, "file26", "pdf");
    createFile(root, "file27", "txt");
    createFile(root, "file28", "pdf");
    createFile(root, "file29", "txt");
    createFile(root, "file30", "pdf");
    createFile(root, "file31", "txt");
    createFile(root, "file32", "pdf");
    createFile(root, "file33", "txt");
    createFile(root, "file34", "pdf");
    createFile(root, "file35", "txt");
    
    printTree(root);
    return 0;
}