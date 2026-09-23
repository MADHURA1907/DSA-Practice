#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        long long total = 0;
        for (int num : nums)
            total += num;

        long long target = total - x;

        // Need to remove the entire array
        if (target == 0)
            return n;

        int left = 0;
        long long sum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {

            sum += nums[right];

            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if (maxLen == -1)
            return -1;

        return n - maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    int result = sol.minOperations(nums, x);
    cout << "Minimum operations: " << result << endl; // Output: 2
    return 0;
}