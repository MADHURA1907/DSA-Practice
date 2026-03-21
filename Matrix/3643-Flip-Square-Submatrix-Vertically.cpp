#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        int n = grid.size();
        int m = grid[0].size();

        // boundary check
        if(x + k > n || y + k > m) return grid;

        for(int i = 0; i < k / 2; i++) {
            for(int j = 0; j < k; j++) {
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }

        return grid;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    Solution obj;
    grid = obj.reverseSubmatrix(grid, 1, 1, 2);

    for(auto &row : grid) {
        for(auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}