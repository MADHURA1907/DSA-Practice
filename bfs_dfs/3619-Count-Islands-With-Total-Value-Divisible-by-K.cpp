
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;

    long long dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == 0) {
            return 0;
        }

        long long value = grid[i][j];
        grid[i][j] = 0;  // Mark visited

        value += dfs(grid, i + 1, j);
        value += dfs(grid, i - 1, j);
        value += dfs(grid, i, j + 1);
        value += dfs(grid, i, j - 1);

        return value;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(grid, i, j);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

int main() {
    Solution s;

    vector<vector<int>> grid = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}
    };

    int k = 5;

    cout << s.countIslands(grid, k) << endl;

    return 0;
}
