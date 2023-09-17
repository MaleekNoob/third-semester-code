#include <iostream>
using namespace std;

// Definition of the node
template <class T>
struct binaryTreeNode
{
    T info;
    binaryTreeNode<T> *left;
    binaryTreeNode<T> *right;
};

// Definition of the class
template <class T>
class binaryTreeType
{
public:
    const binaryTreeType<T> &operator=(const binaryTreeType<T> &); // Overload the assignment operator.

    bool isEmpty() const; // Returns true if the binary tree is empty; otherwise, returns false.

    void inorderTraversal() const; // Function to do an inorder traversal of the binary tree.

    void preorderTraversal() const; // Function to do a preorder traversal of the binary tree.

    void postorderTraversal() const; // Function to do a postorder traversal of the binary tree.

    int treeHeight() const; // Returns the height of the binary tree.

    int treeNodeCount() const; // Returns the number of nodes in the binary tree.

    int treeLeavesCount() const; // Returns the number of leaves in the binary tree.

    void destroyTree(); // Deallocates the memory space occupied by the binary tree; Postcondition: root = NULL;

    binaryTreeType(const binaryTreeType<T> &otherTree); // copy constructor

    binaryTreeType(); // default constructor

    ~binaryTreeType(); // destructor

protected:
    binaryTreeNode<T> *root;

private:
    void copyTree(binaryTreeNode<T> * &copiedTreeRoot, binaryTreeNode<T> * otherTreeRoot); // Makes a copy of the binary tree to which otherTreeRoot points. The pointer copiedTreeRoot points to the root of the copied binary tree.

    void destroy(binaryTreeNode<T> * &p); // Function to destroy the binary tree to which p points. Postcondition: p = NULL
    
    void inorder(binaryTreeNode<T> * p) const; // Function to do an inorder traversal of the binary tree to which p points.

    void preorder(binaryTreeNode<T> * p) const; // Function to do a preorder traversal of the binary tree to which p points.

    void postorder(binaryTreeNode<T> * p) const; // Function to do a postorder traversal of the binary tree to which p points.

    int height(binaryTreeNode<T> * p) const; // Function to return the height of the binary tree to which p points.

    int max(int x, int y) const; // Returns the larger of x and y.

    int nodeCount(binaryTreeNode<T> * p) const; // Function to return the number of nodes in the binary tree to which p points

    int leavesCount(binaryTreeNode<T> * p) const; // Function to return the number of leaves in the binary tree to which p points
};