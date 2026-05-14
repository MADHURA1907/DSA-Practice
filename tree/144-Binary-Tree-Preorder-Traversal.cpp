#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    vector<int> preorder(TreeNode* root,vector<int>& pre)
    {
        if(root==NULL)
        {
            return pre;
        }
        pre.push_back(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
        return pre;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre; 
        if(root==NULL)
        {
            return pre;
        }
        pre=preorder(root,pre);
        return pre;    
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

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
