#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        vector<int> ans;
        for(auto x:freq)
        {
            if(x.second>(n/3))
            {
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums={3,2,3};
    vector<int> ans = s.majorityElement(nums);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}