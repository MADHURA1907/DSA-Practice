#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> newmat(m,vector<int>(n));
        int k=0;
        if((m*n<original.size()) || (m*n>original.size()))
        {
            return {};
        }
        for(int i=0;i<m && k<original.size();i++)
        {
            for(int j=0;j<n&& k<original.size();j++)
            {
                newmat[i][j]=original[k++];
            }
        }
        return newmat;
    }
};

int main()
{
    vector<int> original={1,2,3,4};
    Solution s;
    vector<vector<int>> newmat(2,vector<int>(2));
    newmat=s.construct2DArray(original,2,2);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<newmat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}