#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i + 1 < n && grid[i][j] != grid[i + 1][j])
                    return false;

                if (j + 1 < m && grid[i][j] == grid[i][j + 1])
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 2, 3}, {1, 4, 5}, {6, 7, 8}};
    bool result = s.satisfiesConditions(grid);
    cout << "Satisfies Conditions: " << (result ? "true" : "false") << endl;
    return 0;
}