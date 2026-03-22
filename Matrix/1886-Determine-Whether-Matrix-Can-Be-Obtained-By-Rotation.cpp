#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> rotate(vector<vector<int>>& mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        //take transpose:
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            reverse(mat[i].begin(),mat[i].end());
        }

        return mat;

    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++) {
        if(mat == target) return true;
        rotate(mat);
    }

    return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat={{0,1},{1,0}};
    vector<vector<int>> target={{1,0},{0,1}};
    cout<<s.findRotation(mat,target);
}