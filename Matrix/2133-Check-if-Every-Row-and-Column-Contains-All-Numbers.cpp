#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            vector<int> freqrow(n, 0);
            vector<int> freqcol(n, 0);
            for(int j=0;j<n;j++)
            {
                freqrow[matrix[i][j]-1]++;
                freqcol[matrix[j][i]-1]++;
            }
            for(int j=0;j<n;j++)
            {
                if(freqrow[j]==0)
                {
                    return false;
                }
                if(freqcol[j]==0)
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{3,1,2},{2,3,1}};
    Solution s;
    bool result = s.checkValid(matrix);
    if(result)
    {
        cout << "The matrix is valid." << endl;
    }
    else
    {
        cout << "The matrix is not valid." << endl;
    }
}