#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        bool b=false;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i && b==false)
            {
                ans=nums[i];
                b=true;
            }
            else if(nums[i]!=i)
            {
                ans = ans & nums[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 0, 1};
    cout << s.sortPermutation(nums);
}