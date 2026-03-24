#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int size=n*m;
        vector<int> arr(size);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int index=i*m+j;
                arr[index]=grid[i][j];
            }
        }
        vector<long long> prefix(size,1);
        vector<long long> suffix(size,1);

        for(int i=1;i<size;i++)
        {
            prefix[i] = (prefix[i-1]*arr[i-1])%12345;
        }

        for(int i=size-2;i>=0;i--)
        {
            suffix[i] = (suffix[i+1]*arr[i+1])%12345;
        }

        for(int i=0;i<size;i++)
        {
            arr[i]=(prefix[i]*suffix[i])%12345;
        }

        for(int k=0;k<size;k++)
        {
            int i=k/m;
            int j=k%m;
            grid[i][j]=arr[k];
        }

        return grid;
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,2},{3,4}};
    vector<vector<int>> result = sol.constructProductMatrix(grid);      
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}