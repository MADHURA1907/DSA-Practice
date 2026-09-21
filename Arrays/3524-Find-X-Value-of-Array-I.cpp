#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> cnt(k, 0);

        for (int num : nums) {
            vector<long long> temp(k, 0);

            int x = num % k;

            temp[x]++;

            for (int r = 0; r < k; r++) {
                temp[(r * x) % k] += cnt[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += temp[r];
            }

            cnt = temp;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    vector<long long> result = solution.resultArray(nums, k);

    for (long long val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}