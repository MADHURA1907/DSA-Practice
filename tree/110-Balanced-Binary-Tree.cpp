#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    int check(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left = check(root->left);

        if(left == -1)
        {
            return -1;
        }

        int right = check(root->right);

        if(right == -1)
        {
            return -1;
        }

        if(abs(left - right) > 1)
        {
            return -1;
        }

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};

int main()
{
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

    Solution s;

    if(s.isBalanced(root))
    {
        cout << "Balanced Tree";
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}