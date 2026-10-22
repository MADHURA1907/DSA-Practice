#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool increasing = true;
        bool decreasing = true;

        // Check both possible circular orders.
        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n)
                increasing = false;

            if (nums[i] != (nums[0] - i + n) % n)
                decreasing = false;
        }

        int ans = INT_MAX;

        // nums is a rotation of [0, 1, ..., n-1].
        if (increasing) {
            int k = nums[0];

            if (k == 0)
                ans = 0;
            else
                ans = min(n - k, k + 2);
        }

        // nums is a rotation of [n-1, ..., 1, 0].
        if (decreasing) {
            int k = (n - 1 - nums[0] + n) % n;
            ans = min(ans, min(k + 1, n - k + 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 0, 1};
    cout << s.minOperations(nums);
}