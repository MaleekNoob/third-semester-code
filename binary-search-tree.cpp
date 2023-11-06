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

Node* insertData(Node* &root, int data) {
    if (root == NULL) {
        Node* newNode = new Node(data);
        return newNode;
    }

    if (data < root->data) {
        root->left = insertData(root->left, data);
    } else if (data > root->data) {
        root->right = insertData(root->right, data);
    }

    return root;
}

void inputData(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertData(root, data);
        cin >> data;
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

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->data << " ";
            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}

int main() {

    Node* root = NULL;
    cout << "Enter data for binary search tree (Press -1 to stop): " << endl;
    inputData(root);

    cout << "\nLevel order traversal: ";
    levelOrderTraversal(root);

    return 0;
}