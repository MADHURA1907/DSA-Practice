#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 1, 1, 1};
    bool isUniform = sol.uniformArray(nums1);
    cout << "Is Uniform Array: " << (isUniform ? "True" : "False") << endl;

    return 0;
}