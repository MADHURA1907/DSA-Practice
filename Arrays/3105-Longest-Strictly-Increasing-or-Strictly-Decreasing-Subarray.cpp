#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=1;
        int c=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                c++;
            }
            else
            {
                n=max(n,c);
                c=1;
            }
        }

        n=max(c,n);
        c=1;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                c++;
            }
            else
            {
                n=max(n,c);
                c=1;
            }
        }

        n=max(c,n);

        return n;
        

    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 2, 3, 4, 5};
    cout << s.longestMonotonicSubarray(nums) << endl;
    return 0;
}