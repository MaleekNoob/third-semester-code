#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* right;
    Node* left;

    Node(T data) {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

template <class T>
class BinaryTree {
    private:
    Node<T>* root;

    public:
    BinaryTree() {
        this->root = NULL;
    }

    BinaryTree(Node<T>* root) {
        this->root = root;
    }

    Node<T>* BuildTree() {
        T data;
        cout << "\nEnter data (Enter -1 for NULL): ";
        cin >> data;
        root = new Node<T>(data);

        if (data == -1) {
            return NULL;
        }

        cout << "\nData for Left of " << data;
        root->left = BuildTree();
        cout << "\nData for Right of " << data;
        root->right = BuildTree();
        return root;
    }

    void print() {
        printTree(root);
    }

    void printTree(Node<T>* root) {
        if (root == NULL) {
            return;
        }

        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }

};

int main() {
    BinaryTree<int> tree;
    tree.BuildTree();
    tree.print();
}