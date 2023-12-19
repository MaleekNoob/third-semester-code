#include <iostream>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class AVL {
    private:
    TreeNode* root;

    void displayTreeData(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        displayTreeData(root->left);
        cout << root->data << " ";
        displayTreeData(root->right);
    }

    TreeNode* rightRotation(TreeNode* root) 
    {
        if (root == nullptr || root->left == nullptr) 
        {
            return root;
        }

        TreeNode* pivot = root->left;
        root->left = pivot->right;
        pivot->right = root;

        return pivot;
    }

    TreeNode *leftRotation(TreeNode *root)
    {
        if (root == nullptr || root->right == nullptr)
        {
            return root;
        }

        TreeNode *pivot = root->right;
        root->right = pivot->left;
        pivot->left = root;

        return pivot;
    }

    TreeNode* rightleftRotation(TreeNode *root) 
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    TreeNode* leftRightRotation(TreeNode* root) 
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(getHeight(root->right), getHeight(root->left));
    }

    TreeNode* insertData(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        else if (val > root->data) {
            root->right = insertData(root->right, val);

            if (getHeight(root->left) - getHeight(root->right) < 1) {
                // right heavy
                if (val > root->right->data) {
                    root = leftRotation(root);
                }
                else {
                    root = leftRightRotation(root);
                }
            }
        }
        else if (val < root->data) {
            root->left = insertData(root->left, val);

            if (getHeight(root->left) - getHeight(root->right) > 1)
            {
                // left heavy
                if (val < root->left->data)
                {
                    root = rightRotation(root);
                }
                else
                {
                    root = rightleftRotation(root);
                }
            }
        }

        return root;
    }

    public:
    
    AVL()
    {
        root = nullptr;
    }

    void insert(int val) {
        root = insertData(root, val);
    }

    void display() {
        displayTreeData(root);
    }

};


int main() {

    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    tree.display();

    return 0;
}