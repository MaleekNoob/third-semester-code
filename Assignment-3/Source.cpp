#include <iostream>
using namespace std;

class Node {
public:
    string name;
    string path;
    string type;
    // Node* children;

    Node* left, * right;

    Node() {
        left = NULL;
        right = NULL;
    }

    Node(string name, string path, string type) {
        this->name = name;
        this->path = path;
        this->type = type;
        left = NULL;
        right = NULL;
    }
};

class FileTree {
private:
    Node* root;

    void BuildTree() {
        root = new Node("root", "/root", "directory");
        root->left = new Node("Patients", "/root/Patients", "directory");
        root->right = new Node("logs", "/root/logs", "directory");
    }

    void printTreeData(Node* root) {
        if (root == NULL) {
            return;
        }
        cout << endl << endl << root->name << endl;
        cout << root->type << endl;
        cout << root->path << endl;
        printTreeData(root->left);
        printTreeData(root->right);
    }

public:
    FileTree() {
        BuildTree();
    }

    void createDirectory(Node* root, string name) {
        Node* newNode = new Node(name, root->path + "/" + name, "directory");
        root->left = newNode;
    }

    void display() {
        printTreeData(root);
    }
};

int main() {

    FileTree* tree = new FileTree();
    tree->display();

    return 0;
}