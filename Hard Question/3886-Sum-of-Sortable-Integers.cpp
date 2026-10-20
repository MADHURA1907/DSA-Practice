#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;
            int prevMax = -1;

            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                int descents = 0;
                int mn = nums[start], mx = nums[start];

                for (int j = start; j < end; j++) {
                    if (nums[j] > nums[j + 1])
                        descents++;

                    mn = min(mn, nums[j + 1]);
                    mx = max(mx, nums[j + 1]);
                }

                // A block must be sortable by cyclic rotation.
                if (descents > 1 ||
                    (descents == 1 && nums[start] < nums[end])) {
                    valid = false;
                    break;
                }

                // Consecutive sorted blocks must also be compatible.
                if (start > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    int result = sol.sortableIntegers(nums);
    cout << result << endl; // Output the number of valid k values
    return 0;
}