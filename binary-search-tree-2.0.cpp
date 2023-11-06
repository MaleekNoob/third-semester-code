#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinarySearchTree {
    private:
    Node* root;

    public: 
    BinarySearchTree() {
        root = NULL;
    }

    BinarySearchTree(Node* root) {
        this->root = root;
    }

    void insert(int data) {
        if (root == NULL) {
            root = new Node(data);
            return;
        }

        Node* currentNode = root;
        Node* prevNode = NULL;

        while (currentNode != NULL) {
            prevNode = currentNode;

            if (data < currentNode->data) {
                if (currentNode->left == NULL) {
                    currentNode->left = new Node(data);
                    return;
                }
                currentNode = currentNode->left;
            } else if (data > currentNode->data) {
                if (currentNode->right == NULL) {
                    currentNode->right = new Node(data);
                    return;
                }
                currentNode = currentNode->right;
            }
        }
    }

    void InOrder(Node* root) {
        if (root == NULL) {
            return;
        }

        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }

    void inOrder() {
        InOrder(root);
    }
};


int main() {

    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.inOrder();

    return 0;
}