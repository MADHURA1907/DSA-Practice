#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,5,2,3};
    int target = 2;
    vector<int> result = s.targetIndices(nums,target);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}