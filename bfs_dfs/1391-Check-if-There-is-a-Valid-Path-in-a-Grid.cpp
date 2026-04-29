#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> dirs = {
        {},
        {{0,-1},{0,1}},     // 1
        {{-1,0},{1,0}},     // 2
        {{0,-1},{1,0}},     // 3
        {{0,1},{1,0}},      // 4
        {{0,-1},{-1,0}},    // 5
        {{0,1},{-1,0}}      // 6
    };

    bool isvalid(int i,int j,int m,int n)
    {
        return (i>=0 && i<m && j>=0 && j<n);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0]=true;
        while(!q.empty())
        {
            auto a=q.front();
            q.pop();

            int r=a.first;
            int c=a.second;

            if(r==m-1 && c==n-1)
            {
                return true;
            }

            for(int k = 0; k < dirs[grid[r][c]].size(); k++) 
            {
                int ni = r + dirs[grid[r][c]][k][0];
                int nj = c + dirs[grid[r][c]][k][1];

                if(!isvalid(ni,nj,m,n) || visited[ni][nj]) continue;

                for(auto back : dirs[grid[ni][nj]]) 
                {
                    if(ni + back[0] == r && nj + back[1] == c) 
                    {
                        visited[ni][nj] = true;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return false;   

    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1,2,1},{1,2,1}};
    if(s.hasValidPath(grid))
    {
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }

    return 0;
}