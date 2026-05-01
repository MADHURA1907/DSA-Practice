#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;;
        int f=0;
        for(int i=0;i<nums.size();i++)
        {
            f+=(i*nums[i]);
            sum+=nums[i];
        }
        int m=f;
        int prev=f;

        for(int i=1;i<nums.size();i++)
        {
            f=prev+sum-nums.size()*nums[nums.size()-i];
            prev=f;
            m=max(m,f);
        }

        return m;
        
    }
};

int main()
{
    Solution s;
    vector<int> nums={4,3,2,6};
    cout<<s.maxRotateFunction(nums)<<endl;
    return 0;
}