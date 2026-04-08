#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        for(int i=0;i<queries.size();i++)
        {
            int idk=queries[i][0];
            while(idk<=queries[i][1])
            {
                nums[idk]=(1LL * nums[idk]*queries[i][3]% MOD);
                idk+= queries[i][2];
            }
        }
        int j=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            j= (j^nums[i]);
        }

        return j;
        
    }
};

int main()
{
    Solution s;
    vector<int> nums={1,2,3,4,5};
    vector<vector<int>> queries={{0,4,1,2},{0,3,2,2},{0,4,1,2}};
    cout<<s.xorAfterQueries(nums,queries);
    return 0;
}