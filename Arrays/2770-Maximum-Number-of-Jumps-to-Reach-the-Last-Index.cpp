#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(abs(nums[i] - nums[j]) <= target)
                {
                    if(dp[j]==-1)
                    {
                        continue;
                    }
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n-1];
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 3, 6, 4, 1, 2};
    int target = 2;
    int ans = obj.maximumJumps(nums, target);
    cout << ans << endl;
}



