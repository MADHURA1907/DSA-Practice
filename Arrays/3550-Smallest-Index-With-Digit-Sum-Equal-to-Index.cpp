#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            int sum=0;
            while(x!=0)
            {
                sum += x%10;
                x=x/10;
            }

            if(sum==i)
            {
                return i;
            }

        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = sol.smallestIndex(nums);
    cout << "Smallest index: " << result << endl; // Output: 0
    return 0;
}