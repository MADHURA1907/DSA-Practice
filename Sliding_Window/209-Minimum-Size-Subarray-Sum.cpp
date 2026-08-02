#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,sum=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            while(sum>=target)
            {
                ans=min(ans,i-left+1);
                sum -= nums[left];
                left++;
            }
        }

        return (ans==INT_MAX)?0:ans;
    }
};

int main()
{
    Solution s;
    int target,n;
    cin>>target>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<s.minSubArrayLen(target,nums)<<endl;
}