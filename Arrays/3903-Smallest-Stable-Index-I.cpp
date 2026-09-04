#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int large=INT_MIN;
        for(int i=0;i<n;i++)
        {
            large=max(large,nums[i]);
            int small=INT_MAX;
            for(int j=i;j<n;j++)
            {
                small=min(small,nums[j]);
            }
            int temp=large-small;
            if(temp<=k)
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