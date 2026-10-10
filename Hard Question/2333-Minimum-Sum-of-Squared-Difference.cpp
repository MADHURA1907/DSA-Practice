#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int mx = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            ans += 1LL * diff[i] * diff[i];
        }

        vector<long long> freq(mx + 1, 0);

        for (int d : diff) {
            freq[d]++;
        }

        for (int d = mx; d > 0 && k > 0; d--) {
            long long count = freq[d];
            long long ops = min(k, count);

            // Reduce 'ops' differences from d to d - 1.
            ans -= ops * (2LL * d - 1);

            freq[d] -= ops;
            freq[d - 1] += ops;
            k -= ops;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5, 6};
    int k1 = 3;
    int k2 = 2;
    cout << s.minSumSquareDiff(nums1, nums2, k1, k2) << endl;
    return 0;
}