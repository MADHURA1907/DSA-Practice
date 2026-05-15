#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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

    TreeNode* build(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return NULL;

        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return build(nums, 0, nums.size() - 1);
    }
};

// Inorder Traversal
void inorder(TreeNode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution obj;

    TreeNode* root = obj.sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    inorder(root);

    return 0;
}