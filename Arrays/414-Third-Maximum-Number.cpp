#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums.size()-1,count=1;
        while(i>0)
        {
            if (nums[i] != nums[i - 1]) {
                count++;
                if (count == 3) return nums[i - 1];
            }
            i--;
        }
        
        return nums.back();
        
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    cout<<s.thirdMax(nums);
}