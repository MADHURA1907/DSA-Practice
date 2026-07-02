#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int OR = 0;

            for (int j = i; j < n; j++) {
                OR |= nums[j];

                if (OR >= k) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    Solution obj;

    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = obj.minimumSubarrayLength(nums, k);
    if (result != -1) {
        cout << "Minimum subarray length with OR >= " << k << " is: " << result << endl;
    } else {
        cout << "No subarray found with OR >= " << k << endl;
    }

    return 0;
}