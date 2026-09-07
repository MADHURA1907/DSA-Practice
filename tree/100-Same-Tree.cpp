#include <bits/stdc++.h>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both nodes are NULL
        if (p == NULL && q == NULL)
            return true;

        // One node is NULL
        if (p == NULL || q == NULL)
            return false;

        // Values are different
        if (p->val != q->val)
            return false;

        // Check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main()
{
    Solution s;

    // Tree 1
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    // Call function
    bool result = s.isSameTree(p, q);

    // Print result
    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}