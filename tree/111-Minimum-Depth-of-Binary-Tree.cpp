#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        this->val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:
    
    int minDepth(TreeNode* root) {

        // Base case
        if(root == NULL) {
            return 0;
        }

        // If left subtree is NULL
        if(root->left == NULL) {
            return 1 + minDepth(root->right);
        }

        // If right subtree is NULL
        if(root->right == NULL) {
            return 1 + minDepth(root->left);
        }

        // If both subtrees exist
        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }
};

int main() {

    /*
            1
           / \
          2   3
         /
        4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    Solution obj;

    cout << "Minimum Depth of Binary Tree: "
         << obj.minDepth(root);

    return 0;
}