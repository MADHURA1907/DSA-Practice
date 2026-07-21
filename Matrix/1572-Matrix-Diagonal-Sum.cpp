#include <iostream>
#include <vector>   
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0,j=0,n=mat.size(),m=mat[0].size();
        int sum=0;
        int k=m-1;
        for(int i=0;i<n;i++)
        {
            sum += mat[i][j];
            sum+= mat[i][k];
            j++;
            k--;
        }

        if(m==n && m%2!=0)
        {
            sum -= mat[n/2][m/2];
        }

        return sum;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result = s.diagonalSum(mat);
    cout << "Diagonal Sum: " << result << endl;
    return 0;
}