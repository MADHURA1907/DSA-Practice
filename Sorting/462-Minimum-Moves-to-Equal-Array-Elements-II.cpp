#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m;
        if(n%2==0)
        {m=nums[(n/2)-1];}
        else
        {m=nums[(n/2)];}
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            result += abs(nums[i]-m);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    int result = s.minMoves2(nums);
    cout<<result;
    return 0;
}