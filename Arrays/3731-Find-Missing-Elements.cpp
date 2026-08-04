#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(),nums.end());
        int m_min=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==m_min)
            {
                m_min++;
            }
            else
            {
                result.push_back(m_min);
                m_min++;
                i--;
            }
        }
        return result;

    }
};

int main()
{
    Solution s;
    vector<int> nums={1,2,3,4,5,6,7,8,9,10};
    vector<int> result=s.findMissingElements(nums);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}