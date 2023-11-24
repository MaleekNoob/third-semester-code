#include "TreeNode.h"

class AVL
{
private:
    TreeNode *root;

    int getBalanceFactor(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return getHeight(root->left) - getHeight(root->right);
    }

    TreeNode *balance(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        int balanceFactor = getBalanceFactor(root);

        if (balanceFactor > 1)
        {
            if (getBalanceFactor(root->left) > 0)
            {
                return rightRotate(root);
            }
            else
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if (balanceFactor < -1)
        {
            if (getBalanceFactor(root->right) < 0)
            {
                return leftRotate(root);
            }
            else
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }

    TreeNode *rightRotate(TreeNode *root)
    {
        TreeNode *newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;

        return newRoot;
    }

    TreeNode *leftRotate(TreeNode *root)
    {
        TreeNode *newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;

        return newRoot;
    }

    TreeNode *leftRightRotate(TreeNode *root)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    TreeNode *rightLeftRotate(TreeNode *root)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    TreeNode *insertData(TreeNode *root, string val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < root->value)
        {
            root->left = insertData(root->left, val);
            if (getHeight(root->left) - getHeight(root->right) == 2)
            {
                if (val < root->left->value)
                {
                    root = rightRotate(root);
                }
                else
                {
                    root = leftRightRotate(root);
                }
            }
        }
        else if (val > root->value)
        {
            root->right = insertData(root->right, val);
            if (getHeight(root->right) - getHeight(root->left) == 2)
            {
                if (val > root->right->value)
                {
                    root = leftRotate(root);
                }
                else
                {
                    root = rightLeftRotate(root);
                }
            }
        }
        else
        {
            root->count++;
        }

        root->height = getHeight(root);
        return root;
    }

    bool findPrefix(string word, string prefix) {
        if (word.length() < prefix.length()) {
            return false;
        }

        for (int i = 0; i < prefix.length(); i++) {
            if (word[i] != prefix[i]) {
                return false;
            }
        }

        return true;
    }

    void autocompletePrefix(TreeNode* root, string prefix) {
        if (root == nullptr) {
            return;
        }

        if (findPrefix(root->value, prefix)) {
            cout << endl << "Fruit: " << root->value << endl << "Count: " << root->count << endl;
            // return;
        }

        autocompletePrefix(root->left, prefix);
        autocompletePrefix(root->right, prefix);
    
    }
    
    TreeNode* removeData(TreeNode* root, string data) {
        if (root == nullptr) {
            return nullptr;
        }

        if (data < root->value) {
            root->left = removeData(root->left, data);
        }
        else if (data > root->value) {
            root->right = removeData(root->right, data);
        }
        else {
            if (root->count > 1) {
                root->count--;
            }
            else {
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    return nullptr;
                }
                else if (root->left == nullptr) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == nullptr) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                else {
                    TreeNode* temp = root->right;
                    while (temp->left != nullptr) {
                        temp = temp->left;
                    }

                    root->value = temp->value;
                    root->count = temp->count;
                    root->right = removeData(root->right, temp->value);
                }
            }
        }

        root->height = getHeight(root);
        return balance(root);
    
    }

    void deleteTreeNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        deleteTreeNodes(root->left);
        deleteTreeNodes(root->right);
        delete root;
    }

public:
    AVL() : root(nullptr) {}

    void insert(string data)
    {
        root = insertData(root, data);
    }

    void autocomplete(string prefix)
    {
        autocompletePrefix(root, prefix);
    }

    void remove(string data)
    {
        root = removeData(root, data);
    }

    void deleteTree() {
        deleteTreeNodes(root);
    }

    void empty() {
        root = nullptr;
    }

    void displayMenu() {
        cout << endl << "1. Read file and store data";
        cout << endl << "2. Auto complete data";
        cout << endl << "3. Delete Node";
        cout << endl << "4. Exit";
    }
};