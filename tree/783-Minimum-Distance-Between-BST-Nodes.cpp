#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

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
    void inorder(TreeNode* root, vector<int>& p) {
        if (root == NULL) {
            return;
        }

        TreeNode* t = root;
        p.push_back(t->val);
        inorder(t->left, p);
        inorder(t->right, p);
    }

    int minDiffInBST(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        vector<int> p;
        inorder(root, p);

        int m = INT_MAX;

        for (int i = 0; i < p.size(); i++) {
            for (int j = i + 1; j < p.size(); j++) {
                if (abs(p[i] - p[j]) < m) {
                    m = abs(p[i] - p[j]);
                }
            }
        }

        return m;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    cout << obj.minDiffInBST(root) << endl;

    return 0;
}