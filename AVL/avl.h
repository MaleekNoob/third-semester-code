#pragma once
#include <iostream>
using namespace std;

struct AVLTreeNode {
    int data;
    int height;
    AVLTreeNode* right;
    AVLTreeNode* left;

    AVLTreeNode() : data(0), height(0), right(nullptr), left(nullptr) {}

    AVLTreeNode(int data, int height = 0) : data(data), height(height), right(nullptr), left(nullptr) {}
};

class AVL {
    private:
    AVLTreeNode* root;

    int getBalanceFactor(AVLTreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return getHeight(root->left) - getHeight(root->right);
    }

    AVLTreeNode* balance (AVLTreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        int balanceFactor = getBalanceFactor(root);

        if (balanceFactor > 1) {
            if (getBalanceFactor(root->left) > 0) {
                return rightRotate(root);
            } else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        } else if (balanceFactor < -1) {
            if (getBalanceFactor(root->right) < 0) {
                return leftRotate(root);
            } else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }

    AVLTreeNode* rightRotate(AVLTreeNode* root) {
        AVLTreeNode* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;

        return newRoot;
    }

    AVLTreeNode* leftRotate(AVLTreeNode* root) {
        AVLTreeNode* newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;

        return newRoot;
    }

    AVLTreeNode* leftRightRotate(AVLTreeNode* root) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    AVLTreeNode* rightLeftRotate(AVLTreeNode* root) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    AVLTreeNode* balance(AVLTreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        int balanceFactor = getBalanceFactor(root);

        if (balanceFactor > 1) {
            if (getBalanceFactor(root->left) > 0) {
                return rightRotate(root);
            } else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        } else if (balanceFactor < -1) {
            if (getBalanceFactor(root->right) < 0) {
                return leftRotate(root);
            } else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }

    int getHeight(AVLTreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    AVLTreeNode* insertData(AVLTreeNode* root, int val) {
        if (root == nullptr) {
            return new AVLTreeNode(val);
        }

        if (val < root->data) {
            root->left = insertData(root->left, val);
            if (getHeight(root->left) - getHeight(root->right) == 2) {
                if (val < root->left->data) {
                    root = rightRotate(root);
                } else {
                    root = leftRightRotate(root);
                }
            }
        } else {
            root->right = insertData(root->right, val);
            if (getHeight(root->right) - getHeight(root->left) == 2) {
                if (val > root->right->data) {
                    root = leftRotate(root);
                } else {
                    root = rightLeftRotate(root);
                }
            }
        }

        root->height = getHeight(root);
        return root;
    }

    public:
    AVL() : root(nullptr) {}

    void insert(int data) {
        root = insertData(root, data);
    }
};