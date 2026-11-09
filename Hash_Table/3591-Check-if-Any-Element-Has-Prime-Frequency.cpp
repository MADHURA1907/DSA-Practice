#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool prime(int x)
    {

        if(x==1)
        {
            return false;
        }
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
            {
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x:nums)
        {
            freq[x]++;
        }

        for(auto x: freq)
        {
            if(prime(x.second))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    bool b = s.checkPrimeFrequency(nums);
    if(b)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}