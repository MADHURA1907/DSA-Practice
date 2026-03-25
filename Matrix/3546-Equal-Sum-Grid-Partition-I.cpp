#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                total += grid[i][j];
            }
        }
        long long temp=0;

        for(int i=0;i<n;i++)
        {
            long long rowsum=0;
            for(int j=0;j<m;j++)
            {
                rowsum+= grid[i][j];
            }
            temp += rowsum;
            if((total-temp) == temp)
                {
                    return true;
                }
  
        }
        temp=0;

        for(int i=0;i<m;i++)
        {   long long columnsum=0;
            for(int j=0;j<n;j++)
            {
                columnsum+= grid[j][i];
            }
            temp += columnsum;
            if((total-temp) == temp)
                {
                    return true;
                }
            
  
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    bool result = sol.canPartitionGrid(grid);
    cout << (result ? "true" : "false") << endl;
    return 0;
}