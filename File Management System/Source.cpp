#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

template <typename T>
class queue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *frontNode;
    Node *rearNode;
    size_t count;

public:
    queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    // Insert element at the back of the queue
    void push(const T &value)
    {
        Node *newNode = new Node(value);
        if (empty())
        {
            frontNode = rearNode = newNode;
        }
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    // Remove the element at the front of the queue
    void pop()
    {
        if (!empty())
        {
            Node *temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
            count--;
            if (empty())
            {
                rearNode = nullptr;
            }
        }
        else
        {
            std::cerr << "queue is empty. Cannot pop.\n";
        }
    }

    // Access the element at the front of the queue
    T &front()
    {
        if (!empty())
        {
            return frontNode->data;
        }
        else
        {
            throw std::out_of_range("queue is empty. Cannot access front element.");
        }
    }

    // Access the element at the back of the queue
    T &back()
    {
        if (!empty())
        {
            return rearNode->data;
        }
        else
        {
            throw std::out_of_range("queue is empty. Cannot access back element.");
        }
    }

    // Check if the queue is empty
    bool empty() const
    {
        return count == 0;
    }

    // Return the number of elements in the queue
    size_t size() const
    {
        return count;
    }
};

// Define the structure for the tree node
struct Node {
    string name;
    string path;
    string type;
    list<Node*> children;

    Node() {
        name = "";
        path = "";
        type = "";
    }

    Node(string name) {
        this->name = name;
        path = "";
        type = "";
    }

    Node(string name, string path, string type) {
        this->name = name;
        this->path = path;
        this->type = type;
    }

    Node(Node& node) {
        name = node.name;
        path = node.path;
        type = node.type;
        children = node.children;
    }
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
        root->children.push_back(new Node("PateintData", "root/PateintData", "directory"));
        root->children.push_back(new Node("Logs", "root/Logs", "directory"));
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

    void displayTreeHelper(Node *node, int level)
    {
        if (node == nullptr)
        {
            return;
        }

        // Print the node with indentation
        for (int i = 0; i < level; ++i)
        {
            cout << '\t';
        }
        cout << node->path << " (" << node->type << ")" << endl;

        // Recursively print the children
        for (Node *child : node->children)
        {
            displayTreeHelper(child, level + 1);
        }
    }

    void displayTree()
    {
        if (root == nullptr)
        {
            cout << "Root directory does not exist." << endl;
            return;
        }

        displayTreeHelper(root, 0);
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
            if (current == nullptr) {
                q.pop();
                continue;
            }

            q.pop();

            if (current->path == path) {
                return current;
            }

            Node* child = current->children.front();
            while (child != nullptr) {
                q.push(child);
                child = child->children.front();
            }

        }

        return nullptr;
    }

    // Create a directory by path
    void CreateDirectoryByPath(string path) {
        vector<string> directories;
        stringstream ss(path);
        string dir;

        // Split path by '/'
        while (getline(ss, dir, '/')) {
            directories.push_back(dir);
        }

        // Start from the root
        Node* current = root;

        // Traverse the tree according to the path
        for (int i = 0; i < directories.size() - 1; ++i) {
            bool found = false;
            for (Node* child : current->children) {
                if (child->name == directories[i]) {
                    current = child;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Directory " << directories[i] << " not found." << endl;
                return;
            }
        }

        // Create a new directory and add it to the parent's children
        Node* newDir = new Node(directories.back());
        current->children.push_back(newDir);
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

    Node* GiveParentOf(Node* node) {
        if (node == root) {
            return nullptr;
        }

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

    void FeatureAccess(Node* root) {
        Node *clipboard = nullptr;   // global storage for cut/copied node
        bool isCutOperation = false; // to distinguish between cut and copy operations

        int choice = 0;
        while (choice != 9) {
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
            cout << "14. Merge Directories" << endl;
            cout << "Enter your choice: ";
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
                break;
            case 10:
            {
                string name;
                cout << endl << "Enter the name of the directory to open: ";
                cin >> name;

                Node *node = findNodeByName(name);

                if (node == nullptr) {
                    cout << "Node not found." << endl;
                    break;
                }

                if (node->type != "directory") {
                    cout << "Node is not a directory." << endl;
                    break;
                }

                for (Node* child : root->children) {
                    if (child->name == name) {
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
                if (choice == 2) {
                    string name;
                    cout << "Enter the name of the file or directory to search for: ";
                    cin >> name;

                    Node *node = findNodeByName(name);

                    if (node == nullptr) {
                        cout << "Node not found." << endl;
                        break;
                    }

                    cout << "Path: " << node->path << endl;
                    cout << "Type: " << node->type << endl;
                }
                else if (choice == 1) {
                    string path;
                    cout << "Enter the path of the file or directory to search for: ";
                    cin >> path;

                    Node *node = findNodeByPath(path);

                    if (node == nullptr) {
                        cout << "Node not found." << endl;
                        break;
                    }

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
                txt_file_name += ".txt";

                fstream infile(txt_file_name, ios::in);
                string path;
                deleteTree(root);
                root = nullptr;
                while (getline(infile, path)) {
                    CreateDirectoryByPath(path);
                }
            }
            case 14:
            {
                string toMerge, toMergeWith;
                cout << "Enter name of directory to merge with: ";
                cin >> toMergeWith;
                cout << "Enter name of directory to merge: ";
                cin >> toMerge;
                Node* merge = findNodeByName(toMerge);
                Node* mergeWith = findNodeByName(toMergeWith);
                if (merge == nullptr || mergeWith == nullptr) {
                    cout << "Invalid directory name." << endl;
                    break;
                }
                cout << "Merging " << merge->name << " with " << mergeWith->name << endl;
                for (Node* child : merge->children) {
                    mergeWith->children.push_back(child);
                }
                Node* parentNode = GiveParentOf(merge);
                parentNode->children.remove(merge);
                // delete merge;
                cout << endl << "Merged successfully";
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    // Member function to find a node by its name
    Node *findTreeNode(Node *node, string name)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->name == name)
        {
            return node;
        }

        for (Node *child : node->children)
        {
            Node *result = findTreeNode(child, name);
            if (result != nullptr)
            {
                return result;
            }
        }

        return nullptr;
    }

    // Member function to insert a node into the tree
    // void insertNode(string name, string parent, string type) {
    //     if (parent == "") {
    //         if (type == "directory" && parent == "") {
    //             root = new Node;
    //             root->name = name;
    //             root->path = name;
    //             root->type = type;
    //         }
    //         else {
    //             cout << "Root directory does not exist." << endl;
    //             return;
    //         }
    //     }

    //     // if (parent == "") {
    //     //     if (name == root->name) {
    //     //         // return;
    //     //         return;
    //     //     }
    //     //     else {
    //     //         cout << "Invalid path." << endl;
    //     //         return;
    //     //     }
    //     // }

    //     Node* ParentNode = findTreeNode(root, parent);
    //     if (ParentNode == nullptr) {
    //         cout << "Invalid path." << endl;
    //         return;
    //     }

    //     // Traverse through parent children using while loop to see if name already exists. If it does exist, return
    //     for (Node* child : ParentNode->children) {
    //         if (child->name == name) {
    //             cout << "Node already exists." << endl;
    //             return;
    //         }
    //     }

    //     Node* newNode = new Node;
    //     newNode->name = name;
    //     newNode->path = ParentNode->path + "/" + name;
    //     newNode->type = type;

    //     ParentNode->children.push_back(newNode);

    // }

    void analyzePath(string path) {
        cout << "Path: " << path << endl;
        int nameStartIndex = 0;
        bool is_directory = true;
        string name, parent = "";
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/' || i == path.length() - 1) {
                name = path.substr(nameStartIndex, i);
                if (i == path.length() - 1) {
                    name += path[i];
                }

                for (int j = 0; j < name.length(); j++) {
                    if (name[j] == '.') {
                        is_directory = false;
                        break;
                    }
                }

                if (!is_directory) {
                    // Create a file
                    // insertNode(name, parent, "file");
                }
                else {
                    // Create a directory
                    // insertNode(name, parent, "directory");
                }
                parent = name;
                nameStartIndex = i + 1;
            }
        }
    }

    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        for (Node* child : node->children) {
            deleteTree(child);
        }

        delete node;
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
