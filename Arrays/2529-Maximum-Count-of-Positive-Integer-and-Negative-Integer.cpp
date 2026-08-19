#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int pos=0,neg=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                neg++;
            }
            else if(nums[i]>0)
            {
                pos++;
            }
        }
        return max(pos,neg);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-3,-2,-1,0,0,1,2};
    cout<<s.maximumCount(nums)<<endl;
    return 0;
}