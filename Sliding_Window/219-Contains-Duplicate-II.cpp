#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size() && abs(i - j) <= k; j++)
            {
                if(nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    bool result = solution.containsNearbyDuplicate(nums, k);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}