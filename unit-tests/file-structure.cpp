/*
Remaining:
Import feature

Bug:
Merge directories
*/

#include "stackstructure.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <filesystem>
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

    // Function to remove a node from the list
    void remove(T value) {
        listNode<T> *current = head;
        listNode<T> *prev = nullptr;
        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
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

    // get child node by name
    TreeNode *getChild(string name)
    {
        listNode<TreeNode *> *current = children.getHead();
        while (current != nullptr)
        {
            if (current->data->name == name)
            {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    TreeNode* getChild(TreeNode* node) {
        listNode<TreeNode *> *current = children.getHead();
        while (current != nullptr)
        {
            if (current->data == node)
            {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    void addChild(TreeNode* node) {
        children.push_back(node);
    }

    void printTreeNode() {
        cout << setw(50) << name << setw(70) << " (" << type << ") " << setw(150) << path << endl;
    }
};

class FileManagementTree {
    private:
    TreeNode *root;
    Stack<TreeNode *> *stack = new Stack<TreeNode *>();

    void choiceValidationOneToTen(int &num) {
        if (num < 1 || num > 14) {
            cout << endl << "Invalid operation. Please select between 1 to 10: ";
            cin >> num;
        }
    }

    TreeNode* FindTreeNodeByPath(TreeNode* root, string path) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->path == path) {
            return root;
        }
        TreeNode* temp = nullptr;
        listNode<TreeNode *> *traverse = root->children.getHead();
        while (traverse != nullptr)
        {
            temp = FindTreeNodeByPath(traverse->data, path);
            if (temp != nullptr) {
                return temp;
            }
            traverse = traverse->next;
        }
        return nullptr;
    }

    TreeNode* FindTreeNode(TreeNode* root, string name) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->name == name) {
            return root;
        }
        TreeNode* temp = nullptr;
        listNode<TreeNode *> *traverse = root->children.getHead();
        while (traverse != nullptr)
        {
            temp = FindTreeNode(traverse->data, name);
            if (temp != nullptr) {
                return temp;
            }
            traverse = traverse->next;
        }
        return nullptr;
    }

    void CreateNewTreeNode(string name, string ParentName /*, string path*/, string type)
    {
        if (root == nullptr) {
            if (type == "directory" && ParentName == "") {
                root = new TreeNode(name, name, type);
            }
            else {
                cout << endl << "Invalid path";
                return;
            }
        }

        if (ParentName == "") {
            if (name == root->name) {
                /* do nothing */
                return;
            }
            else {
                cout << endl << "Root already full";
                return;
            }
        }

        TreeNode* parent = FindTreeNode(root, ParentName);
        if (parent == nullptr) {
            cout << endl << "Invalid path";
            return;
        }

        // Traverse through parent children to see if name already exists. If it does exist, return
        listNode<TreeNode *> *traverse = parent->children.getHead();
        while (traverse != nullptr)
        {
            if (name == traverse->data->name)
            {
                return;
            }
            traverse = traverse->next;
        }

        parent->children.push_back(new TreeNode(name, parent->path + "/" + name, type));
    }

    void breakPathComponents(string path) {
        int starting_Index = 0;
        bool is_directory = true;
        string name, ParentName = "";
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == '/' || i == path.length() - 1)
            {
                name = "";
                int limit = i;
                if (i == path.length() - 1)
                {
                    limit++;
                }
                for (int j = starting_Index; j < limit; j++)
                {
                    if (path[j] == '.')
                    {
                        is_directory = false;
                    }
                    name += path[j];
                }
                starting_Index = i + 1;

                if (is_directory)
                    CreateNewTreeNode(name, ParentName, "directory");
                else
                    CreateNewTreeNode(name, ParentName, "file");

                ParentName = name;
                is_directory = true;
            }
        }
        cout << endl;
    }

    void exportStructure(TreeNode *node, const std::filesystem::path &parentPath)
    {
        if (node == NULL)
        {
            return;
        }

        std::filesystem::path currentPath = parentPath / node->name;

        if (node->type == "directory")
        {
            std::filesystem::create_directories(currentPath);
        }
        else if (node->type == "file")
        {
            std::ofstream outFile(currentPath);
        }

        for (listNode<TreeNode *> *current = node->children.getHead(); current != NULL; current = current->next)
        {
            exportStructure(current->data, currentPath);
        }
    }

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
            cout << root->name << setw(24) << " (" << root->type << ") " << setw(24) << root->path << endl;

            listNode<TreeNode *> *current = root->children.getHead();
            while (current != nullptr)
            {
                displayTree(current->data);
                current = current->next;
            }
        }
    }

    // Function to delete the tree and free memory
    void deleteTree(TreeNode *root)
    {
        if (root != nullptr)
        {
            listNode<TreeNode *> *current = root->children.getHead();
            while (current != nullptr)
            {
                deleteTree(current->data);
                current = current->next;
            }
            delete root;
        }
    }

    void CreateFileAndDirectories(TreeNode *current)
    {
        int choice = 0;
        while (choice != 14)
        {
            cout << endl
                << current->path;
            cout << endl
                << "Current Directory: " << current->name << " " << current->type;
            cout << endl
                << endl
                << "List of children: ";
            listNode<TreeNode *> *traverse = current->children.getHead();
            int i = 0;
            while (traverse != nullptr)
            {
                cout << endl
                    << traverse->data->type << " " << i + 1 << ": " << traverse->data->name;
                traverse = traverse->next;
                i++;
            }

            cout << endl << "\n1. Open Specific directory\n2. Create new Directory\n3. Create new File\n4. Level Order Display\n5. Merge Directories\n6. Delete\n7. Rename\n8. Search by name or content\n9. Copy\n10. Cut\n11. Paste\n12. Export\n13. Import\n14. Exit\nEnter choice: ";
            cin >> choice;
            choiceValidationOneToTen(choice);
            switch (choice)
            {
                case 1:
                {
                    /* Open Specific directory */
                    int choice = 0;
                    cout << endl << "1. Open by name\n2. Open by path\nEnter choice: ";
                    cin >> choice;
                    if (choice == 1) {
                        cout << endl << "Enter the name of directory: ";
                        string directory_name;
                        cin >> directory_name;
                        traverse = current->children.getHead();
                        while (traverse != nullptr)
                        {
                            if (directory_name == traverse->data->name && traverse->data->type == "directory")
                            {
                                CreateFileAndDirectories(traverse->data);
                            }
                            if (traverse->data->type != "directory")
                            {
                                cout << endl
                                    << "File cannot be further opened";
                            }
                            traverse = traverse->next;
                        }
                    }
                    else if (choice == 2) {
                        string directory_path;
                        cout << endl << "Enter the path of directory: ";
                        cin >> directory_path;
                        TreeNode* temp = FindTreeNodeByPath(root, directory_path);
                        if (temp == nullptr) {
                            cout << endl << "Invalid path";
                            break;
                        }
                        CreateFileAndDirectories(temp);
                    }
                    else {
                        cout << endl << "Invalid choice";
                    }

                    break;
                }

                case 2:
                {
                    /* Create new Directory */
                    int directoryChoice = 0;
                    cout << endl << "1. Create new directory in current directory\n2. Create new directory by path\nEnter choice: ";
                    cin >> directoryChoice;

                    if (directoryChoice == 1) {
                        cout << endl << "Enter directory name: ";
                        string directory_name;
                        cin >> directory_name;
                        createDirectory(current, directory_name);
                        cout << endl << "New directory created successfully";
                    }
                    else {
                        string path;
                        cout << endl << "Enter path: ";
                        cin >> path;
                        breakPathComponents(path);
                    }
                    break;
                }

                case 3:
                {
                    /* Create new File */
                    string file_name, file_type;
                    cout << endl
                        << "Enter file name: ";
                    cin >> file_name;
                    cout << endl
                        << "Enter file type: ";
                    cin >> file_type;
                    createFile(current, file_name, file_type);
                    cout << endl
                        << "New file created successfully";
                    break;
                }

                case 4:
                {
                    /* Level-order traversal */
                    displayFileStructure();
                    break;
                }

                case 5: 
                {
                    /* Merge directories */
                    string inMerge, toMerge;
                    int mergeChoice = 0;
                    cout << endl << "1. Merge by name\n2. Merge by path\nEnter choice: ";
                    cin >> mergeChoice;

                    if (mergeChoice == 1) {
                        cout << endl << "Enter the name of directory in which you want to merge: ";
                        cin >> inMerge;
                        cout << endl << "Enter the name of directory which you want to merge: ";
                        cin >> toMerge;
                    }
                    else if (mergeChoice == 2) {
                        cout << endl << "Enter the path of directory in which you want to merge: ";
                        cin >> inMerge;
                        cout << endl << "Enter the path of directory which you want to merge: ";
                        cin >> toMerge;

                        TreeNode* temp = FindTreeNodeByPath(root, inMerge);
                        if (temp == nullptr) {
                            cout << endl << "Invalid path";
                            break;
                        }
                        inMerge = temp->name;

                        temp = FindTreeNodeByPath(root, toMerge);
                        if (temp == nullptr) {
                            cout << endl << "Invalid path";
                            break;
                        }
                        toMerge = temp->name;
                    }

                    TreeNode* inMergeNode = nullptr;
                    TreeNode* toMergeNode = nullptr;

                    listNode<TreeNode *> *traverse = current->children.getHead();
                    while (traverse != nullptr)
                    {
                        if (inMerge == traverse->data->name && traverse->data->type == "directory")
                        {
                            inMergeNode = traverse->data;
                        }
                        if (toMerge == traverse->data->name && traverse->data->type == "directory")
                        {
                            toMergeNode = traverse->data;
                        }
                        traverse = traverse->next;
                    }

                    if (inMergeNode == nullptr || toMergeNode == nullptr) {
                        cout << endl << "Invalid directory name";
                        break;
                    }

                    listNode<TreeNode *> *traverse2 = toMergeNode->children.getHead();
                    while (traverse2 != nullptr)
                    {
                        inMergeNode->children.push_back(traverse2->data);
                        traverse2 = traverse2->next;
                    }

                    current->children.remove(toMergeNode);
                    cout << endl << "Directories merged successfully";
                    break;
                }

                case 6:
                {
                    /* Delete */
                    string file_name;
                    cout << endl << "Enter name of file or directory to be deleted: ";
                    cin >> file_name;
                    traverse = current->children.getHead();
                    while (traverse != nullptr)
                    {
                        if (file_name == traverse->data->name)
                        {
                            current->children.remove(traverse->data);
                            cout << endl << "File or directory deleted successfully";
                            break;
                        }
                        traverse = traverse->next;
                    }
                    break;
                }

                case 7:
                {
                    /* Rename */
                    string file_name;
                    cout << endl << "Enter name of file or directory to be renamed: ";
                    cin >> file_name;
                    traverse = current->children.getHead();
                    while (traverse != nullptr)
                    {
                        if (file_name == traverse->data->name)
                        {
                            cout << endl << "Enter new name: ";
                            cin >> file_name;
                            traverse->data->name = file_name;
                            cout << endl << "File or directory renamed successfully";
                            break;
                        }
                        traverse = traverse->next;
                    }
                    break;
                }

                case 8:
                {
                    /* Search by name or content */
                    int name_or_content = 0;
                    cout << endl << "1. Search by name\n2. Search by content\nEnter choice: ";
                    cin >> name_or_content;

                    while (name_or_content < 1 || name_or_content > 2) {
                        cout << endl << "Invalid choice. Please select between 1 to 2: ";
                        cin >> name_or_content;
                    }

                    if (name_or_content == 1) {
                        string file_name;
                        cout << endl << "Enter name of file or directory to be searched: ";
                        cin >> file_name;
                        traverse = current->children.getHead();
                        while (traverse != nullptr)
                        {
                            if (file_name == traverse->data->name)
                            {
                                cout << "Name" << setw(20) << " (type) " << setw(25) << "Path" << endl;
                                traverse->data->printTreeNode();
                                break;
                            }
                            traverse = traverse->next;
                        }
                    }
                    else if (name_or_content = 2) {
                        string file_content;
                        cout << endl << "Enter content of file to be searched(file type): ";
                        cin >> file_content;
                        traverse = current->children.getHead();
                        while (traverse != nullptr)
                        {
                            if (file_content == traverse->data->type)
                            {
                                cout << "Name" << setw(20) << " (type) " << setw(25) << "Path" << endl;
                                traverse->data->printTreeNode();
                            }
                            traverse = traverse->next;
                        }
                    }
                    else {
                        cout << endl << "Invalid choice";
                    }

                    break;
                }

                case 9:
                {
                    /* Copy */
                    string file_name;
                    cout << endl << "Enter name of file or directory to be copied: ";
                    cin >> file_name;
                    traverse = current->children.getHead();
                    while (traverse != nullptr)
                    {
                        if (file_name == traverse->data->name)
                        {
                            stack->push(traverse->data);
                            cout << endl << "File or directory copied successfully" << endl;
                            break;
                        }
                        traverse = traverse->next;
                    }
                    break;
                }

                case 10:
                {
                    /* Cut */
                    string file_name;
                    cout << endl << "Enter name of file or directory to be cut: ";
                    cin >> file_name;
                    traverse = current->children.getHead();
                    while (traverse != nullptr)
                    {
                        if (file_name == traverse->data->name)
                        {
                            stack->push(traverse->data);
                            current->children.remove(traverse->data);
                            cout << endl << "File or directory cut successfully" << endl;
                            break;
                        }
                        traverse = traverse->next;
                    }
                    break;
                }

                case 11:
                {
                    /* Paste */
                    if (stack->empty()) {
                        cout << endl << "No file or directory to paste" << endl;
                        break;
                    }
                    TreeNode *temp = stack->pop();
                    current->children.push_back(temp);
                    cout << endl << "File or directory pasted successfully" << endl;
                    break;
                }

                case 12:
                {
                    /* Exporting file structure */
                    std::filesystem::path currentPath = std::filesystem::current_path();
                    exportStructure(root, currentPath);
                    break;
                }

                case 13:
                {
                    /* Importing */
                    string txt_file_name;
                    cout << endl << "Enter the name of file from which file structure is to be imported (File must be of .txt type): ";
                    cin >> txt_file_name;
                    txt_file_name += ".txt";
                    fstream file(txt_file_name, ios::in);
                    
                    if (!file.is_open()) {
                        cout << endl << "File not found" << endl;
                        break;
                    }

                    string path = "";
                    deleteTree(root);
                    root = nullptr;
                    while (!file.eof()) {
                        getline(file, path);
                        breakPathComponents(path);
                    }
                    
                    // if (!file.is_open()) {
                    //     cout << endl << "File not found" << endl;
                    //     break;
                    // }

                    // string path = "";
                    // deleteTree(root);
                    // root = nullptr;
                    // while (!file.eof()) {
                    //     getline(file, path);
                    //     breakPathComponents(path);
                    // }
                    CreateFileAndDirectories(root);
                    exit(0);
                    break;
                }

                case 14:
                {
                    break;
                }

                default:
                {
                    cout << "Heavy Error";
                    break;
                }
            }
        }
    }

public:
    FileManagementTree() {  /*Build tree*/
        // Create the root directory
        root = new TreeNode("root", "root", "directory");

        // Create directories and files
        createDirectory(root, "PatientData");
        createDirectory(root, "Logs");
    }

    void UserCommandInterface() {
        TreeNode *current = root;
        CreateFileAndDirectories(current);
    }

    void displayFileStructure() {
        TreeNode *current = root;
        cout << endl << endl << "File Structure: ";
        displayTree(current);
    }

    void deallocateMemory() {
        deleteTree(root);
    }

};

int main()
{
    /*
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
    */

   FileManagementTree filetree;
   filetree.UserCommandInterface();
   filetree.deallocateMemory();

    return 0;
}