#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> temp(n, vector<char>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                temp[i][j] = boxGrid[m - 1 - j][i];
            }
        }

        for(int j = 0; j < m; j++) {

            for(int i = n - 1; i >= 0; i--) {

                if(temp[i][j] == '.') {

                    for(int k = i - 1; k >= 0; k--) {

                        if(temp[k][j] == '*')
                            break;

                        if(temp[k][j] == '#') {

                            temp[i][j] = '#';
                            temp[k][j] = '.';
                            break;
                        }
                    }
                }
            }
        }

        return temp;
    }
};

int main()
{
    Solution sol;

    vector<vector<char>> boxGrid = {
        {'#', '.', '#'},
        {'#', '*', '.'},
        {'.', '.', '.'}
    };

    vector<vector<char>> result = sol.rotateTheBox(boxGrid);

    for (const auto& row : result) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}