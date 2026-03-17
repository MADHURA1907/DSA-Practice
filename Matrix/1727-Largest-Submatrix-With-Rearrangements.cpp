#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int area = 0;

        vector<int> height(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                    height[j]=0;
                else
                    height[j]+=1;
            }

            vector<int> temp = height;

            sort(temp.begin(), temp.end());

            for(int j=0;j<m;j++)
            {
                int h = temp[j];
                int w = m - j;
                area = max(area, h * w);
            }
        }

        return area;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{0,0,1},{1,1,1},{1,0,1}};
    cout << sol.largestSubmatrix(matrix) << endl; 
    return 0;
}