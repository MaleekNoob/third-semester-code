#include <iostream>
#include <queue>
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

    Node* deleteNode(Node* root, int data) {
        if (root == NULL) {
            return NULL;
        }

        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        } else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* minNode = root->right;
                while (minNode->left != NULL) {
                    minNode = minNode->left;
                }
                root->data = minNode->data;
                root->right = deleteNode(root->right, minNode->data);
            }
        }

        return root;
    }

    void deleteData(int data) {
        root = deleteNode(root, data);
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

    void levelOrderDisplay() {
        if (root == NULL) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* currentNode = q.front();
            q.pop();

            cout << currentNode->data << " ";

            if (currentNode->left != NULL) {
                q.push(currentNode->left);
            }

            if (currentNode->right != NULL) {
                q.push(currentNode->right);
            }
        }
    
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