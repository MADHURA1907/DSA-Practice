#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int large=INT_MIN;
        vector<int> suffixmin(n);
        suffixmin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixmin[i]=min(suffixmin[i+1],nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            large=max(large,nums[i]);

            if((large-suffixmin[i])<=k)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 6, 4, 2};
    int k = 3;
    int index = sol.firstStableIndex(nums, k);
    cout << "First Stable Index: " << index << endl;

    return 0;
}