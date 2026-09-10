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
    int result=0;
    int findsum(TreeNode* root,int& count)
    {
        if(root==NULL)
        {
            return 0;
        }

        count ++;
        int lsum = findsum(root->left,count);
        int rsum = findsum(root->right,count);
        return lsum + rsum + root->val; 
    }
    int averageOfSubtree(TreeNode* root) {

        if(root==NULL)
        {
            return 0;
        }
        int result=0;
        int count=0;
        int sum =  findsum(root,count);
        if(root->val==sum/count)
        {
            result++;
        }
        int l= averageOfSubtree(root->left);
        int r= averageOfSubtree(root->right);

        return l+r+result;

    }
};

int main()
{
    Solution s;
    TreeNode* nn =new TreeNode(4);
    nn->left =new TreeNode(8);
    nn->right =new TreeNode(5);
    nn->left->left =new TreeNode(0);
    nn->left->right =new TreeNode(1);
    nn->right->right =new TreeNode(6);
    s.averageOfSubtree(nn);
    return 0;
}