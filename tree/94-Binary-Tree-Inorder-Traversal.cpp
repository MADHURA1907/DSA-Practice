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
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode* > st;
        if(root==NULL)
        {
            return inorder;
        }

        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
        return inorder;

    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;
    vector<int> ans = obj.inorderTraversal(root);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}

