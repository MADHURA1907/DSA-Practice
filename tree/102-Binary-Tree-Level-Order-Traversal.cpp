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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> temp;
        if(!root)
        {
            return result;
        }
        queue<TreeNode* > q;
        q.push(root);
        int n=1;

        while(!q.empty())
        {
            int count=0;
            for(int i=0;i<n;i++)
            {TreeNode* t=q.front();
                temp.push_back(t->val);
            
            q.pop();
            if(t->left) {q.push(t->left); count++;}
            if(t->right){q.push(t->right); count++;}
            }
            n=count;
            result.push_back(temp);
            temp.clear();
        }
        return result;;
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

    vector<vector<int>> result = s.levelOrder(root);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}