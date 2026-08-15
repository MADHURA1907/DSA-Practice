#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int countzero=(nums[0]==0)?1:0;
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==0)
            {
                countzero++;
            }
            ans=(ans^nums[i]);
        }

        if(countzero==n)
        {
            return 0;
        }
        if(ans==0)
        {
            return n-1;
        }
        return n;
    }
};

int main()
{
    vector<int> nums={1,2,3};
    Solution s;
    cout<<s.longestSubsequence(nums)<<endl;
}