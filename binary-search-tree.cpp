#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node() {
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
    Node* root;

    public:
    BinarySearchTree() {
        this->root = nullptr;
    }

    BinarySearchTree(int data) {
        this->root = new Node(data);
    }

    void insert(int data) {
        this->root = insertNode(this->root, data);
    }

    Node* insertNode(Node* node, int data) {
        if (node == nullptr) {
            Node* newNode = new Node(data);
            return newNode;
        }
        if (data < node->data) {
            node->left = insertNode(node->left, data);
        } else {
            node->right = insertNode(node->right, data);
        }
        return node;
    }

    void Delete(int data) {
        this->root = deleteNode(this->root, data);
    }

    Node* deleteNode(Node* node, int data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    void print() {
        Node* address = root;
        display(address);
    }

    void display(Node* node) {
        if (node == NULL) {
            return;
        }
        display(node->left);
        cout << " " << node->data;
        display(node->right);
    }
};

int main() {

    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(11);
    bst.insert(-5);
    bst.insert(0);
    bst.insert(2);
    bst.insert(77);
    bst.insert(41);
    bst.insert(-14);
    bst.insert(115);
    bst.insert(-9);

    bst.print();
    cout << endl;

    bst.Delete(11);
    bst.Delete(-14);
    bst.Delete(0);

    bst.print();

    return 0;
}