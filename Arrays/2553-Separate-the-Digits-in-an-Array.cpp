#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> d;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> temp;
            int n=nums[i];
            while(n!=0)
            {
                temp.push_back(n%10);
                n=n/10;
            }
            reverse(temp.begin(),temp.end());
             for(int j = 0; j < temp.size(); j++) {
                d.push_back(temp[j]);
            }
        }
        return d;

    }
};

int main()
{
    Solution obj;
    vector<int> nums = {13, 25, 83, 77};
    vector<int> ans = obj.separateDigits(nums);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
}