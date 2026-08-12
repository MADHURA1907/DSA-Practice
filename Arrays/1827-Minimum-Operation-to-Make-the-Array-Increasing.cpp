#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int s=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                int diff = nums[i-1]+1-nums[i];
                nums[i] += diff;
                s += diff;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1};
    int result = s.minOperations(nums);
    cout << "Minimum operations needed: " << result << endl;

    return 0;
}