#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<bool> covered(n, false);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                if(intervals[i][0] <= intervals[j][0] &&
                   intervals[j][1] <= intervals[i][1]) {
                    covered[j] = true;
                }
            }
        }

        int cnt = 0;
        for(bool x : covered)
            if(!x) cnt++;

        return cnt;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start and end):" << endl;
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int result = obj.removeCoveredIntervals(intervals);
    cout << "The number of remaining intervals after removing covered ones is: " << result << endl;

    return 0;
}