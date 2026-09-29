#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int t[101][101][201];


    bool solve(int i, int j, int opencount,vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        opencount += (grid[i][j] == '(') ? 1 : -1;

         // Invalid parentheses balance
        if(opencount < 0)
            return false;


        if(t[i][j][opencount] != -1)
        {
            return t[i][j][opencount];
        }

        // Reached destination
        if(i == m - 1 && j == n - 1)
        {
            return opencount == 0;
        }

        // Down
        if(i + 1 < m && solve(i + 1, j, opencount, grid))
        {
            return t[i][j][opencount] = true;
        }

        // Right
        if(j + 1 < n &&
           solve(i, j + 1, opencount, grid))
        {
            return t[i][j][opencount] = true;
        }

        return t[i][j][opencount] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if((m+n-1)%2==1)
        {
            return false;
        }

        if(grid[0][0]==')' || grid[m-1][n-1] == '(')
        {
            return false;
        }

        memset(t,-1,sizeof(t));
        return solve(0, 0, 0, grid);
    }
};

int main()
{
    Solution sol;
    cout<<"Enter the number of rows and columns: ";
    int m, n;
    cin >> m >> n;
    cout<<"Enter the grid elements (only '(' and ')'):\n";
    vector<vector<char>> grid(m, vector<char>(n));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    if(sol.hasValidPath(grid))
    {
        cout << "There is a valid path from the top-left to the bottom-right corner." << endl;
    }
    else
    {
        cout << "There is no valid path from the top-left to the bottom-right corner." << endl;
    }
    return 0;
}
