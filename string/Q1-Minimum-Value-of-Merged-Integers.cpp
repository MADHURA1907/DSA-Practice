#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int m=INT_MAX;
        for(int i=0;i<nums.size();i=i+2)
        {
            string s=to_string(nums[i]);
            s+=to_string(nums[i+1]);
            int x=stoi(s);
            m=min(m,x);
        }
        return m;
        
    }
};

int main()
{
    Solution s;
    cout<<s.minMergedInteger({12, 34, 56, 78})<<endl;
}