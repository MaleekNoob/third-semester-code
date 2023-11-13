/*
#include <iostream>
#include <string>

using namespace std;

// Define a structure for a linked list node
template <typename T>
struct ListNode
{
    T data;
    ListNode *next;

    // Constructor for creating a new node
    ListNode(T value) : data(value), next(nullptr) {}
};

// Define a linked list class
template <typename T>
class LinkedList
{
public:
    ListNode<T> *head;

    // Constructor
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void push_back(T value)
    {
        ListNode<T> *newNode = new ListNode<T>(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            ListNode<T> *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to display the linked list
    void displayList()
    {
        ListNode<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~LinkedList()
    {
        ListNode<T> *current = head;
        ListNode<T> *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }
};

// Define a structure for a tree node
struct TreeNode
{
    string name;
    string path;
    string type;                     // "file" or "directory"
    LinkedList<TreeNode *> children; // Linked list to store multiple child nodes

    // Constructor for creating a new node
    TreeNode(string n, string p, string t) : name(n), path(p), type(t) {}
};

class FileTree {
    private:
        TreeNode* root;

        void BuildTree() {
            root = new TreeNode("root", "/root", "directory");
            root->children.push_back(new TreeNode("Patients", "/root/Patients", "directory"));
            root->children.push_back(new TreeNode("logs", "/root/logs", "directory"));
        }

        void printTreeData(TreeNode* root) {
            if (root == NULL) {
                return;
            }
            cout << endl << endl << root->name << endl;
            cout << root->type << endl;
            cout << root->path << endl;
            root->children.displayList();
            printTreeData(root->children.head->data);
            printTreeData(root->children.head->next->data);
        }

    public:
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
                root->children.displayList();
                ListNode<TreeNode*> *current = root->children.head;
                while (current != nullptr)
                {
                // displayTree(current->data);
                // current = current->next;
                }
            }
        }

        // Function to delete the tree and free memory
        void deleteTree(TreeNode *root)
        {
            if (root != nullptr)
            {
                ListNode<TreeNode*> *current = root->children.head;
                while (current != nullptr)
                {
                deleteTree(current->data);
                current = current->next;
                }
                delete root;
            }
        }
};

int main()
{
    // Create the root directory
    TreeNode *root = new TreeNode("Root", "/", "directory");

    FileTree* tree;

    // Create directories and files
    tree->createDirectory(root, "PatientData");
    tree->createDirectory(root, "Logs");

    tree->createFile(root->children.head->data, "Patient1", "txt");
    tree->createFile(root->children.head->data, "Patient2", "pdf");
    tree->createFile(root->children.head->next->data, "Log1", "txt");

    // Display the tree
    cout << "File Directory Tree:" << endl;
    tree->displayTree(root);

    // Memory cleanup (free allocated memory)
    tree->deleteTree(root);

    return 0;
}
*/

#include <iostream>
#include <string>
// #include <list>

using namespace std;

// Define a structure for a linked list node
template <class T>
class listNode
{
public:
    T data;
    listNode *next;

    // Constructor for creating a new node
    listNode(T value) : data(value), next(nullptr) {}
};

// Define a linked list class
template <class T>
class list
{
private:
    listNode<T> *head;

public:
    // Constructor
    list() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void push_back(T value)
    {
        listNode<T> *newNode = new listNode<T>(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            listNode<T> *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to display the linked list
    void displayList()
    {
        listNode<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~list()
    {
        listNode<T> *current = head;
        listNode<T> *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to get the head of the list
    listNode<T> *getHead()
    {
        return head;
    }

    // Function to get the tail of the list
    listNode<T> *getTail()
    {
        listNode<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current;
    }
};

// Define a structure for a tree node
struct TreeNode
{
    string name;
    string path;
    string type;               // "file" or "directory"
    list<TreeNode *> children; // Linked list to store multiple child nodes

    // Constructor for creating a new node
    TreeNode(string n, string p, string t) : name(n), path(p), type(t) {}
};

// Function to create a new directory in the tree
TreeNode *createDirectory(TreeNode * parent, string dirName)
{
    string dirPath = parent->path + "/" + dirName;
    TreeNode *newDir = new TreeNode(dirName, dirPath, "directory");
    parent->children.push_back(newDir);
    return newDir;
}

// Function to create a new file in the tree
TreeNode *createFile(TreeNode * parent, string fileName, string fileType)
{
    string filePath = parent->path + "/" + fileName + "." + fileType;
    TreeNode *newFile = new TreeNode(fileName, filePath, "file");
    parent->children.push_back(newFile);
    return newFile;
}

// Function to display the tree (pre-order traversal)
void displayTree(TreeNode * root)
{
    if (root != nullptr)
    {
        cout << root->name << " (" << root->type << ") - " << root->path << endl;
        // for (TreeNode *child : root->children)
        // {
        //     displayTree(child);
        // }

        listNode<TreeNode *> *current = root->children.getHead();
        while (current != nullptr)
        {
            displayTree(current->data);
            current = current->next;
        }
    }
}

// Function to delete the tree and free memory
void deleteTree(TreeNode * root)
{
    if (root != nullptr)
    {
        // for (TreeNode *child : root->children)
        // {
        //     deleteTree(child);
        // }
        listNode<TreeNode *> *current = root->children.getHead();
        while (current != nullptr)
        {
            deleteTree(current->data);
            current = current->next;
        }
        delete root;
    }
}

int main()
{
    // Create the root directory
    TreeNode *root = new TreeNode("Root", "/", "directory");

    // Create directories and files
    createDirectory(root, "PatientData");
    createDirectory(root, "Logs");

    createFile(root->children.getHead()->data, "Patient1", "txt");
    createFile(root->children.getHead()->data, "Patient2", "pdf");
    createFile(root->children.getTail()->data, "Log1", "txt");

    // Display the tree
    cout << "File Directory Tree:" << endl;
    displayTree(root);

    // Memory cleanup (free allocated memory)
    deleteTree(root);

    return 0;
}
