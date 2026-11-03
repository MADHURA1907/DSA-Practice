#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x=*max_element(nums.begin(),nums.end());
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            count += (x - nums[i]);
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    cout<<s.minMoves(nums);
}