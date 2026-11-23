#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        vector<long long> arr;

        for(int i = 0; i < nums.size(); i++) {
            arr.push_back(abs((long long)nums[i]));
        }

        sort(arr.begin(), arr.end());

        long long totalPairs = 0;
        int left = 0;

        for(int right = 0; right < arr.size(); right++) {

            while(arr[right] > 2 * arr[left]) {
                left++;
            }

            totalPairs += right - left;
        }

        return totalPairs;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 1, 6, 2, 5};
    cout << s.perfectPairs(nums) << endl;
    return 0;
}