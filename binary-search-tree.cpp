#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    private:
    Node* root;

    public:

    BST() {
        root = nullptr;
    }

    BST(Node* root) {
        this->root = root;
    }

    // BST* insert(BST* root, int data) {
    //     if (root == NULL) {
    //         return new BST(data);
    //     }

    //     if (root->data < data) {
    //         root->right = insert(root->right, data);
    //     }
    //     else if (root->data > data) {
    //         root->left = insert(root->left, data);
    //     }

    //     return root;
    // }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (root == NULL) {
            root = newNode;
            return;
        }

        Node* temp = root;
        while (temp != NULL) {
            if (temp->data < data) {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
            else if (temp->data > data) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
        }
    }

};

int main() {

    // BST b, *root = NULL;
    // root = b.insert(root, 50);
    // root = b.insert(root, 30);
    // root = b.insert(root, 20);
    // root = b.insert(root, 40);
    // root = b.insert(root, 70);
    // root = b.insert(root, 60);
    // root = b.insert(root, 80);

    // b.inorder(root);

    return 0;
}