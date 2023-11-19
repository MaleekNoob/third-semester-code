#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <fstream>
#include <iomanip>

using namespace std;

// Define the structure for the tree node
struct Node {
    string name;
    string path;
    string type;
    list<Node*> children;
};

// Define the class for the file management system
class FileManagementSystem {
private:
    Node* root;

public:
    // Constructor
    FileManagementSystem() {
        root = nullptr;
    }

    // Member function to create the root directory
    void createRoot() {
        if (root == nullptr) {
            root = new Node;
            root->name = "root";
            root->path = "root";
            root->type = "directory";
            cout << "Root directory created successfully." << endl;
        }
        else {
            cout << "Root directory already exists." << endl;
        }
    }

    // Member function to create a new directory within another directory
    void createDirectory(Node* parent) {
        string name;
        cout << "Enter the name of the directory: ";
        cin >> name;

        Node* newDirectory = new Node;
        newDirectory->name = name;
        newDirectory->path = parent->path + "/" + name;
        newDirectory->type = "directory";

        parent->children.push_back(newDirectory);

        cout << "Directory created successfully." << endl;
    }

    // Member function to create a new file within a directory
    void createFile(Node* parent) {
        string name;
        cout << "Enter the name of the file: ";
        cin >> name;

        Node* newFile = new Node;
        newFile->name = name;
        newFile->path = parent->path + "/" + name;
        newFile->type = "file";

        parent->children.push_back(newFile);

        cout << "File created successfully." << endl;
    }

    // Member function to delete a file or directory
    void deleteNode(Node* node) {
        if (node == root) {
            cout << "Cannot delete the root directory." << endl;
            return;
        }

        Node* parent = getParent(node);
        parent->children.remove(node);
        delete node;

        cout << "Node deleted successfully." << endl;
    }

    // Member function to display the tree structure in level order
    void displayTree() {
        if (root == nullptr) {
            cout << "Root directory does not exist." << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->path << " (" << current->type << ")" << endl;

            for (Node* child : current->children) {
                q.push(child);
            }
        }
    }

    // Assuming you have a global variable to hold the cut node
    Node *cutNodeStorage = nullptr;

    // Member function to cut a file or directory
    void cutNode(Node *node)
    {
        // Check if there is already a node in the cut storage
        if (cutNodeStorage != nullptr)
        {
            std::cout << "Error: A node is already cut. Paste or discard it before cutting another node.\n";
            return;
        }

        // Remove the node from its parent's children list
        Node *parent = getParent(node);
        parent->children.remove(node);

        // Store the node in the cut storage
        cutNodeStorage = node;
    }

    // Assuming you have a global variable to hold the copied node
    Node *copiedNodeStorage = nullptr;

    // Function to create a deep copy of a node
    Node *deepCopyNode(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        // Create a new node with the same data
        Node *newNode = new Node();
        newNode->name = node->name;
        newNode->path = node->path;
        newNode->type = node->type;

        // Copy children
        for (Node *child : node->children)
        {
            newNode->children.push_back(deepCopyNode(child));
        }

        return newNode;
    }

    // Member function to copy a file or directory
    void copyNode(Node *node)
    {
        // Check if there is already a node in the copy storage
        if (copiedNodeStorage != nullptr)
        {
            std::cout << "Error: A node is already copied. Paste or discard it before copying another node.\n";
            return;
        }

        // Store a deep copy of the node in the copy storage
        copiedNodeStorage = deepCopyNode(node);
    }

    // Member function to paste a cut or copied file or directory
    void pasteNode(Node* parent) {
        // Check if there is a node in the cut storage
        if (cutNodeStorage != nullptr)
        {
            // Add the node to the parent's children list
            parent->children.push_back(cutNodeStorage);

            // Clear the cut storage
            cutNodeStorage = nullptr;
        }
        // Check if there is a node in the copy storage
        else if (copiedNodeStorage != nullptr)
        {
            // Add a deep copy of the node to the parent's children list
            parent->children.push_back(deepCopyNode(copiedNodeStorage));
        }
        else
        {
            std::cout << "Error: No node is cut or copied.\n";
        }
    }

    // Member function to rename a file or directory
    void renameNode(Node* node) {
        string newName;
        cout << "Enter the new name: ";
        cin >> newName;

        node->name = newName;

        cout << "Node renamed successfully." << endl;
    }

    // Member function to find a node by its name
    Node* findNodeByName(string name) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->name == name) {
                return current;
            }

            for (Node* child : current->children) {
                q.push(child);
            }
        }

        return nullptr;
    }

    // Member function to find a node by its path
    Node* findNodeByPath(string path) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->path == path) {
                return current;
            }

            for (Node* child : current->children) {
                q.push(child);
            }
        }

        return nullptr;
    }

    // Member function to write the path of all nodes to a file
    void writePathOfAllNodes(Node* node, ofstream& file) {
        if (node == nullptr) {
            return;
        }

        file << node->path << endl;

        for (Node* child : node->children) {
            writePathOfAllNodes(child, file);
        }
    }

    void FeatureAccess(Node* root) {
        Node *clipboard = nullptr;   // global storage for cut/copied node
        bool isCutOperation = false; // to distinguish between cut and copy operations

        int choice;
        while (true) {
            cout << endl << "Path: " << root->path << endl; // "root" is the name of the root directory.
            cout << endl << "Current Directory: " << root->name << endl;
            cout << endl << endl << "List of Children: " << endl;

            // Display the list of children
            for (Node* child : root->children) {
                cout << child->name << " (" << child->type << ")" << endl;
            }
            cout << endl;

            cout << "-----------------------------" << endl;
            cout << "File Management System Menu" << endl;
            cout << "-----------------------------" << endl;
            cout << "1. Create Directory" << endl;
            cout << "2. Create File" << endl;
            cout << "3. Delete Node" << endl;
            cout << "4. Display Tree" << endl;
            cout << "5. Cut Node" << endl;
            cout << "6. Copy Node" << endl;
            cout << "7. Paste Node" << endl;
            cout << "8. Rename Node" << endl;
            cout << "9. Exit" << endl;
            cout << "10. Open Specific Directory" << endl;
            cout << "11. Search for a file or directory" << endl;
            cout << "12. Export" << endl;
            cout << "13. Import" << endl;
            cout << "Enter your choice: " << endl;
            cin >> choice;

            switch (choice) {
            case 1: {
                Node* parent = root;
                createDirectory(parent);
                break;
            }
            case 2: {
                Node *parent = root;
                createFile(parent);
                break;
            }
            case 3: {
                string name;
                cout << endl << "Enter the name of the file or directory to delete: ";
                cin >> name;
                for (Node* child : root->children) {
                    if (child->name == name) {
                        deleteNode(child);
                        break;
                    }
                }
                break;
            }
            case 4:
                displayTree();
                break;
            case 5:
            {
                // Cut node functionality
                string name;
                cout << endl << "Enter the name of the file or directory to cut: ";
                cin >> name;
                for (Node* child : root->children) {
                    if (child->name == name) {
                        cutNode(child);
                        break;
                    }
                }
                break;
            }
            case 6:
            {
                // Copy node functionality
                string name;
                cout << endl << "Enter the name of the file or directory to copy: ";
                cin >> name;
                for (Node* child : root->children) {
                    if (child->name == name) {
                        copyNode(child);
                        break;
                    }
                }
                break;
            }
            case 7:
            {
                // Paste node functionality
                pasteNode(root);
                break;
            }
            case 8: {
                string name;
                cout << endl << "Enter the name of the file or directory to rename: ";
                cin >> name;
                for (Node* child : root->children) {
                    if (child->name == name) {
                        renameNode(child);
                        break;
                    }
                }
                break;
            }
            case 9:
                exit(0);
                break;
            case 10:
            {
                string path;
                cout << "Enter the path of the directory to open: ";
                cin >> path;

                for (Node* child : root->children) {
                    if (child->path == path) {
                        FeatureAccess(child);
                        break;
                    }
                }

                break;
            }
            case 11:
            {
                int choice = 0;
                cout << endl << "1. Search by path" << endl;
                cout << "2. Search by name" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1) {
                    string name;
                    cout << "Enter the name of the file or directory to search for: ";
                    cin >> name;

                    Node *node = findNodeByName(name);
                    cout << "Path: " << node->path << endl;
                    cout << "Type: " << node->type << endl;
                }
                else if (choice == 2) {
                    string path;
                    cout << "Enter the path of the file or directory to search for: ";
                    cin >> path;

                    Node *node = findNodeByPath(path);
                    cout << "Name: " << node->name << endl;
                    cout << "Type: " << node->type << endl;
                }
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }

            }
            case 12:
            {
                string txt_file_name;
                cout << endl << "Enter name of file to export file structure in: ";
                cin >> txt_file_name;
                ofstream file(txt_file_name + ".txt");

                if (!file.is_open()) {
                    cout << endl << "Error opening file." << endl;
                }
                
                writePathOfAllNodes(root, file);
                break;
            }
            case 13:
            {
                string txt_file_name;
                cout << endl << "Enter name of file to import file structure from: ";
                cin >> txt_file_name;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    void UserInterface() {
        // Create the root directory
        createRoot();
        FeatureAccess(root);
    }

private:
    // Helper function to get the parent node of a given node
    Node* getParent(Node* node) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (Node* child : current->children) {
                if (child == node) {
                    return current;
                }
                q.push(child);
            }
        }

        return nullptr;
    }
};

int main() {
    FileManagementSystem fms;
    fms.UserInterface();
    return 0;
}
