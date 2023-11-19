#pragma once
# include "List.h"

// Define a structure for a tree node
struct TreeNode
{
    string name;
    string path;
    string type;               // "file" or "directory"
    list<TreeNode *> children; // Linked list to store multiple child nodes

    // Constructor for creating a new node
    TreeNode(string n, string p, string t) : name(n), path(p), type(t) {}

    // get child node by name
    TreeNode *getChild(string name)
    {
        listNode<TreeNode *> *current = children.getHead();
        while (current != nullptr)
        {
            if (current->data->name == name)
            {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    TreeNode *getChild(TreeNode *node)
    {
        listNode<TreeNode *> *current = children.getHead();
        while (current != nullptr)
        {
            if (current->data == node)
            {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    void addChild(TreeNode *node)
    {
        children.push_back(node);
    }

    void printTreeNode()
    {
        cout << setw(50) << name << setw(70) << " (" << type << ") " << setw(150) << path << endl;
    }
};