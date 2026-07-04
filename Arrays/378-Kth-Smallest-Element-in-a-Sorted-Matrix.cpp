#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> mat;
        int count=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                mat.push_back(matrix[i][j]);
            }
        }

        sort(mat.begin(),mat.end());
        return mat[k-1];
        
    }
};

int main() {
    Solution obj;

    int n, m, k;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = obj.kthSmallest(matrix, k);
    cout << "The " << k << "-th smallest element in the matrix is: " << result << endl;

    return 0;
}