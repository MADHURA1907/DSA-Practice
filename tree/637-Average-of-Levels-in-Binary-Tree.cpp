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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(!root)
        {
            return result;
        }

        queue<TreeNode* >  q;
        q.push(root);
        int n=1;

        while(!q.empty())
        {
            int count = 0;
            double avg=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                avg += t->val;
                if(t->left) {q.push(t->left);count++;}
                if(t->right){q.push(t->right);count++;}
            }
            result.push_back(avg/n);
            n=count;
        }
        return result;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<double> result = s.averageOfLevels(root);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}