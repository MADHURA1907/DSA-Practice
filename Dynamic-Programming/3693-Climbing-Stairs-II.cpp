#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int c(int i, vector<int>& costs, int n, vector<int>& dp)
    {
        if(i == n)
        {
            return 0;
        }

        if(dp[i] != -1)
        {
            return dp[i];
        }

        int tempo = INT_MAX;

        for(int j = 1; j <= 3; j++)
        {
            if(i + j <= n)
            {
                tempo = min(tempo, costs[i+j-1] + j*j + c(i+j, costs, n, dp));
            }
        }

        return dp[i] = tempo;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return c(0, costs, n, dp);
    }
};

int main()
{
    Solution s;
    int n = 5;
    vector<int> costs = {1, 100, 1, 1, 100};
    int ans = s.climbStairs(n, costs);
    cout << ans << endl;
}