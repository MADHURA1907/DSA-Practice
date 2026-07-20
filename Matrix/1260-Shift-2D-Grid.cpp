#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;

        k %= total;

        vector<int> shift(total);

        // Flatten and shift directly
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int oldIndex = i * m + j;
                int newIndex = (oldIndex + k) % total;
                shift[newIndex] = grid[i][j];
            }
        }

        // Convert back to 2D
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = shift[idx++];
            }
        }

        return grid;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 1;
    vector<vector<int>> result = s.shiftGrid(grid, k);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}