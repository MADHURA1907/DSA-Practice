#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int i=0,j=1,n=nums.size();
        while(i<n && j<n-1)
        {
            if(nums[i]>nums[j])
            {
                int val=nums[j+1];
                nums.erase(nums.begin() + j+1);
                nums.insert(nums.begin() + i+1, val);
                i++;
            }j++;
    
        }
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,1,2,4};
    vector<int> result = s.resultArray(nums);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}