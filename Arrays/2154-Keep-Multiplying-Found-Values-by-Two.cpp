#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]==original)
            {
                original=original*2;
                i=-1;
            }
            i++;        
        }
        return original;
        
    }
};

int main()
{
    Solution s;
    vector<int> nums={5,3,6,1,12};
    int original=3;
    cout<<s.findFinalValue(nums,original);
    return 0;
}