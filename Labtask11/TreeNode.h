#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
    string value;
    int count;
    int height;

    TreeNode *left;
    TreeNode *right;

    TreeNode(string val) {
        value = val;
        count = 1;
        height = 1;

        left = nullptr;
        right = nullptr;
    }
};