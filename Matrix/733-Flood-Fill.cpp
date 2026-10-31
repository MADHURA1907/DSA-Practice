#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c,
             int original, int color) {

        int m = image.size();
        int n = image[0].size();

        // Boundary check and color check
        if(r < 0 || c < 0 || r >= m || c >= n ||
           image[r][c] != original) {
            return;
        }

        // Change color
        image[r][c] = color;

        // Four directions
        dfs(image, r + 1, c, original, color);
        dfs(image, r - 1, c, original, color);
        dfs(image, r, c + 1, original, color);
        dfs(image, r, c - 1, original, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int original = image[sr][sc];

        // Avoid infinite recursion
        if(original == color) {
            return image;
        }

        dfs(image, sr, sc, original, color);

        return image;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}