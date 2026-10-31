#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {

        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> left(m, vector<long long>(n, 0));
        vector<vector<long long>> up(m, vector<long long>(n, 0));

        // Starting position
        left[0][0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // Starting cell is processed without reflection
                if(i == 0 && j == 0) {

                    if(j + 1 < n)
                        left[i][j + 1] = 1;

                    if(i + 1 < m)
                        up[i + 1][j] = 1;

                    continue;
                }

                if(grid[i][j] == 1) {

                    // Entered from left -> reflected down
                    if(i + 1 < m) {
                        up[i + 1][j] =
                            (up[i + 1][j] + left[i][j]) % MOD;
                    }

                    // Entered from above -> reflected right
                    if(j + 1 < n) {
                        left[i][j + 1] =
                            (left[i][j + 1] + up[i][j]) % MOD;
                    }

                }
                else {

                    long long ways = (left[i][j] + up[i][j]) % MOD;

                    // Move right
                    if(j + 1 < n) {
                        left[i][j + 1] =
                            (left[i][j + 1] + ways) % MOD;
                    }

                    // Move down
                    if(i + 1 < m) {
                        up[i + 1][j] =
                            (up[i + 1][j] + ways) % MOD;
                    }
                }
            }
        }

        // Total ways to reach bottom-right
        return (left[m - 1][n - 1] + up[m - 1][n - 1]) % MOD;
    }
};

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.uniquePaths(grid);

    cout << result << endl;

    return 0;
}