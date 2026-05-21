#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        vector<vector<int>> reshape(r, vector<int>(c));

        int n = mat.size();
        int m = mat[0].size();

        if (r * c != n * m) {
            return mat;
        }

        vector<int> row;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row.push_back(mat[i][j]);
            }
        }

        int k = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                reshape[i][j] = row[k];
                k++;
            }
        }

        return reshape;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}
    };

    int r = 1;
    int c = 4;

    vector<vector<int>> result = obj.matrixReshape(mat, r, c);

    cout << "Reshaped Matrix:" << endl;

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}