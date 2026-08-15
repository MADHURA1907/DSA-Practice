#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> result;
 
        if(n==1)
        {
            for(int i=0;i<m;i++)
            {
                result.push_back(matrix[0][i]);
            }
        }
        else if(m==1)
        {
            for(int i=0;i<n;i++)
            {
                result.push_back(matrix[i][0]);
            }
        }
        else
        {
            int left=0,right=m-1,top=0,bottom=n-1; //top,bottom: row; left,right: column
            while(left<=right && top<=bottom)
            {
                for(int i=left;i<=right;i++)
                {
                    result.push_back(matrix[top][i]);
                }
                top++;

                for(int i=top;i<=bottom;i++)
                {
                    result.push_back(matrix[i][right]);
                }
                right--;

                if(top <= bottom)
                {
                    for(int i = right; i >= left; i--)
                    {
                        result.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }

               if(left <= right)
                {
                    for(int i = bottom; i >= top; i--)
                    {
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
        }

        return result;


    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}