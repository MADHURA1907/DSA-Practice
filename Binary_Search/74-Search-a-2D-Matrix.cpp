#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int high = (r * c) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[mid / c][mid % c] == target) {
                return true;
            }
            else if (matrix[mid / c][mid % c] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    if (obj.searchMatrix(matrix, target))
        cout << "Target found" << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}