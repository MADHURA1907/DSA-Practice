#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m=-1, j=-1,i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]>m)
            {
                m=nums[i];
                j=i;
            }
        }

        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=m)
            {
                if(2*nums[i]>m)
                {
                    break;
                }
            }
        }

        if(i==nums.size())
        {
            return j;
        }
        return -1;
        
    }
};

int main()
{
    Solution s;
    vector<int> nums={3,6,1,0};
    cout<<s.dominantIndex(nums);
    return 0;
}