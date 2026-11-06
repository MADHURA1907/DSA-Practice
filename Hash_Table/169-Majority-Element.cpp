#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int, int>freq;
        for(int x:nums)
        {
            freq[x]++;
        }
        for(auto it:freq)
        {
            if(it.second>n)
            {
                return it.first;
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums={3,2,3};
    cout<<s.majorityElement(nums)<<endl;
    return 0;   
}