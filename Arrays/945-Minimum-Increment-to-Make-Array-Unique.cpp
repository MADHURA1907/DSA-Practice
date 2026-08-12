#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
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
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    int result = s.minIncrementForUnique(nums);
    cout << "Minimum increments needed: " << result << endl;

    return 0;
}