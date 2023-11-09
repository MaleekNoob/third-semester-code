/*
You have been enlisted by a company specializing in medical device embedded systems. They are
developing a new medical device that necessitates a compact operaƟng system for debugging purposes.
This operatng system will exclusively manage files categorized as paƟent data, device seƫngs, and logs.
Your mission is to create a File Directory Tree Shell customized for their specific needs.
NOTE: YOU MAY RESTIRCT THIS TO BINARY TREE AND MAINTAIN ONLY PATIENT DATA AND LOGS.
1. Implement a tree data structure to represent files and directories within the operaƟng system.
Each node in the tree should have the following aƩributes:
• Name: The name of the file or directory.
• Path: The full path to the file or directory.
• Type: IndicaƟon of whether the node is a directory or file.
• Children: A list of child nodes.
2. Develop a funcƟon to create a new directory within the tree. Users should be able to specify the
directory name.
3. Create a funcƟon to create new files within the tree, allowing users to specify the name, type
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

int main () {
    Node* root = createNode("root", "root", "directory");
    createDirectory(root, "dir1");
    createDirectory(root, "dir2");
    createDirectory(root, "dir3");
    createFile(root, "file1", "txt");
    createFile(root, "file2", "pdf");
    createFile(root, "file3", "txt");
    createFile(root, "file4", "pdf");
    printTree(root);
    return 0;
}