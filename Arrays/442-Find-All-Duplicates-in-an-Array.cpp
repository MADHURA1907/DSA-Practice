#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> a(maxVal+1,0);
        vector<int> arr;
        for(int i=0;i<nums.size();i++)
        {
            a[nums[i]]++;
        }
        for(int i=0;i<maxVal+1;i++)
        {
            if(a[i]>1)
            {arr.push_back(i);}
        }

        return arr;
        
    }
};

int main()
{
    Solution s;
    vector<int> nums={4,3,2,7,8,2,3,1};
    vector<int> arr=s.findDuplicates(nums);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}