#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=(nums[i]*nums[i]);
        }   
        sort(nums.begin(),nums.end());
        return nums;

        
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> result = solution.sortedSquares(nums);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}