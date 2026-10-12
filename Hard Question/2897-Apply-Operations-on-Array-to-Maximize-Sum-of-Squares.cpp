#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> bits(31, 0);

        // Count set bits at each position
        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if (num & (1 << b)) {
                    bits[b]++;
                }
            }
        }

        long long ans = 0;

        // Greedily construct k numbers with maximum set bits
        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int b = 0; b < 31; b++) {
                if (bits[b] > 0) {
                    num |= (1LL << b);
                    bits[b]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    int k = 3;
    cout << s.maxSum(nums, k) << endl;
    return 0;
}