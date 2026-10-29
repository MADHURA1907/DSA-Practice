#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int i, vector<int>& nums)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1,nums);

        temp.pop_back();
        solve(i+1,nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        return ans;

    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> ans = sol.subsets(nums);
    for(auto x: ans)
    {
        for(auto y: x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}