#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        if(nums.size()==k)
        {
            return *max_element(nums.begin(),nums.end());
        }
        int n=nums.size();
        if(k == 1)
        {
            int ans = -1;

            for(int x : nums)
            {
                if(count(nums.begin(), nums.end(), x) == 1)
                {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        if(nums[0]>nums[nums.size()-1])
        {
            if(count(nums.begin(), nums.end(), nums[0]) == 1)
            {
                return nums[0];
            }
            else if(count(nums.begin(), nums.end(), nums[nums.size()-1]) == 1)
            {
                return nums[nums.size()-1];
            }
        }
        else if(nums[0]<nums[nums.size()-1])
        {
            if(count(nums.begin(), nums.end(), nums[nums.size()-1]) == 1)
            {
                return nums[nums.size()-1];
            }
            else if(count(nums.begin(), nums.end(), nums[0]) == 1)
            {
                return nums[0];
            }
        }

        return -1;    
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    s.largestInteger(nums, 1);
    cout<<s.largestInteger(nums, 1)<<endl;
    return 0;
}