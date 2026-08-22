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
    int maxLevelSum(TreeNode* root) {
        int m=INT_MIN;
        if(!root)
        {
            return 0;
        }

        queue<TreeNode* > q;
        q.push(root);
        int n=1;
        int ans=1;
        int level = 1;
        while(!q.empty())
        {
            int count=0;
            int add=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                add += t->val;
                if(t->left) {q.push(t->left);count++;}
                if(t->right) {q.push(t->right);count++;}
            }
            if(m<add)
            {
                ans=level;
                m=add;
            }
            n=count;
            level++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    int result = s.maxLevelSum(root);
    cout<<result;
    return 0;
}