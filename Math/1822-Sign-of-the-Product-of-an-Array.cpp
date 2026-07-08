#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negative=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                return 0;
            }
            if(nums[i]<0)
            {
                negative++;
            }
        }
        if(negative%2!=0)
        {
            return -1;
        }
        return 1;
    }
};

int main()
{
    vector<int> nums={-1,-2,-3,-4,3,2,1};
    Solution obj;
    cout<<obj.arraySign(nums)<<endl;
    return 0;
}