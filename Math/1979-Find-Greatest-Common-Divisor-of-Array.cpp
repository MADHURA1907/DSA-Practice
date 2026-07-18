#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int small=INT_MAX;
        int large=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            small=min(small,nums[i]);
            large= max(large,nums[i]);
        }
        return gcd(small,large);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 5, 6, 9, 10};
    int result = s.findGCD(nums);
    cout << result << endl;
    return 0;
}