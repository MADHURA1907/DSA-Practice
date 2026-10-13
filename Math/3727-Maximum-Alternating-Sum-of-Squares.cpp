#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long score = 0;
        int i=0;
        int n=nums.size();
        
            for(int i=0;i<n/2;i++)
            {
                score -= pow(nums[i],2);
            }
            for(int i=n/2;i<n;i++)
            {
                score += pow(nums[i],2);
            }
        
        

        return score;

        
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.maxAlternatingSum(nums) << endl;
    return 0;
}   