#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node() {
            this->data = 0;
            this->left = NULL;
            this->right = NULL; 
        }

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinaryTree {
    private:
        Node* root;

    public:
    BinaryTree() {
        root = NULL;
    }

    BinaryTree(int data) {
        root = new Node(data);
    }

    BinaryTree(Node* root) {
        this->root = root;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == NULL) {
            root = newNode;
            return;
        }

        Node* temp = root;
        while (temp != NULL) {
            if (data < temp->data) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            } else {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    Node* Delete(Node* root, int data) {
        if (root == NULL) {
            return root;
        }

        if (data < root->data) {
            root->left = Delete(root->left, data);
            return root;
        }
        else if (data > root->data) {
            root->right = Delete(root->right, data);
            return root;
        }

        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* succ = root->right;
            Node* Parentsucc = root;

            while (succ->left != NULL) {
                Parentsucc = succ;
                succ = succ->left;
            }

            if (Parentsucc != root) {
                Parentsucc->left = succ->right;
            }
            else {
                
            }

            delete succ;
            return Parentsucc;
        }
        
    }

    void print() {
        int choice;
        cout << "\n1. Preorder\n2. Inorder\n3. Postorder\nEnter your choice: ";
        cin >> choice;
        while (choice < 1 || choice > 3) {
            cout << "Invalid choice. Enter again: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            Preorder(root);
            break;

        case 2:
            Inorder(root);
            break;

        case 3:
            Postorder(root);
            break;

        default:
            break;
        }
    }

    void Preorder(Node* root) {
        if (root == NULL) {
            return;
        }

        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Inorder(Node* root) {
        if (root == NULL) {
            return;
        }

        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }

    void Postorder(Node* root) {
        if (root == NULL) {
            return;
        }

        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
};