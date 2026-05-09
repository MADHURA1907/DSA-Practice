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

    bool check(TreeNode* t1,TreeNode* t2)
    {
        if(t1==NULL && t2==NULL)
        {
            return true;
        }
        if(t1==NULL || t2==NULL || t1->val != t2->val)
        {
            return false;
        }

        return check(t1->left,t2->right) && check(t1->right,t2->left); 
    }
    bool isSymmetric(TreeNode* root) {
       if(root==NULL)
       {
        return true;
       } 
       return check(root->left,root->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;
    bool ans = obj.isSymmetric(root);
    cout<<ans;
}