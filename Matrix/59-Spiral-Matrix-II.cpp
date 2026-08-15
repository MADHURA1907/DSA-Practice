#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix1(n, vector<int>(n));
        int top=0,bottom=n-1,left=0,right=n-1;
        int j=1;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                matrix1[top][i]=j;
                j++;
            }
            top++;

            for(int i=top;i<=bottom;i++)
            {
                matrix1[i][right]=j++;
            }
            right--;

            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    matrix1[bottom][i]=j++;
                }
                bottom--;
            }

            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    matrix1[i][left]=j++;
                }
                left++;
            }
        }
        return matrix1;
    }
};

int main()
{
    int n=3;
    Solution s;
    vector<vector<int>> result=s.generateMatrix(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}