#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    int a=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=a;
                }
            }
        }
        return;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    cout << "Sorted Colors: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}