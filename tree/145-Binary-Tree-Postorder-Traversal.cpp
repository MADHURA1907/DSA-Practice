#include <iostream>
#include <vector>
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

    vector<int> postorder(TreeNode* root,  vector<int> & arr)
    {
        if(root==NULL)
        {
            return arr;
        }

        postorder(root->left,arr);
        postorder(root->right,arr);
        arr.push_back(root->val);
        return arr;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        if(root==NULL)
        {
            return arr;
        }

        postorder(root,arr);
        return arr;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;

    vector<int> result = obj.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}