#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<n;i++)
        {
            reverse(image[i].begin(),image[i].end());
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (image[i][j]==0)
                {
                    image[i][j]=1;
                }
                else if (image[i][j]==1)
                {
                    image[i][j]=0;
                }
            }
        }

        return image;

    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {{1,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> result = sol.flipAndInvertImage(image);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}