#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL)
        {
            if(root->val==val)
            {
                return root;
            }
            else if(root->val<val)
            {
                root=root->right;
            }
            else
            {
                root=root->left;
            }
        }
        
            return NULL;
        
    }
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
};

int main()
{
    Solution s;
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    int val=2;
    TreeNode* a=s.searchBST(root,val);
    cout<<"Inorder Traversal of the subtree rooted at node with value "<<val<<": ";
    s.inorder(a);
    return 0;
}