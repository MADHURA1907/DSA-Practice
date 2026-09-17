#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int sum = 0;
        int ans = INT_MAX;

        unordered_map<int, int> mp;

        // prefix sum 0 occurs before index 0
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            // Check if a subarray ending at i has sum = target
            if (mp.find(sum - target) != mp.end()) {
                int j = mp[sum - target] + 1;
                int len = i - j + 1;

                // There is a previous non-overlapping subarray
                if (j > 0 && best[j - 1] != INT_MAX) {
                    ans = min(ans, len + best[j - 1]);
                }

                // Store the shortest target subarray ending at i
                if (i == 0)
                    best[i] = len;
                else
                    best[i] = min(best[i - 1], len);
            }
            else {
                // No new target subarray ending at i
                if (i > 0)
                    best[i] = best[i - 1];
            }

            // Store latest prefix sum index
            mp[sum] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int sum = 0;
        int ans = INT_MAX;

        unordered_map<int, int> mp;

        // prefix sum 0 occurs before index 0
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            // Check if a subarray ending at i has sum = target
            if (mp.find(sum - target) != mp.end()) {
                int j = mp[sum - target] + 1;
                int len = i - j + 1;

                // There is a previous non-overlapping subarray
                if (j > 0 && best[j - 1] != INT_MAX) {
                    ans = min(ans, len + best[j - 1]);
                }

                // Store the shortest target subarray ending at i
                if (i == 0)
                    best[i] = len;
                else
                    best[i] = min(best[i - 1], len);
            }
            else {
                // No new target subarray ending at i
                if (i > 0)
                    best[i] = best[i - 1];
            }

            // Store latest prefix sum index
            mp[sum] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.minSumOfLengths(arr, target) << endl;

    return 0;
}