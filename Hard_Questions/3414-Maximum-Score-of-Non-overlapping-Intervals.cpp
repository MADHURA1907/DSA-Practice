#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct Node {
        long long score;
        vector<int> idxs;

        Node() {
            score = 0;
        }

        Node(long long s, vector<int> v) {
            score = s;
            idxs = v;
        }
    };

    vector<vector<Node>> t;
    vector<int> nextIdx;
    int n;

    Node solve(vector<vector<int>>& intervals, int i, int k) {

        // Base case
        if (k == 0 || i >= n) {
            return Node();
        }

        // Already calculated
        if (t[i][k].score != -1) {
            return t[i][k];
        }

        // Option 1: Skip current interval
        Node skip = solve(intervals, i + 1, k);

        // Current interval
        int weight = intervals[i][2];
        int idx = intervals[i][3];

        // First interval whose left > current right
        int j = nextIdx[i];

        // Option 2: Take current interval
        Node temp = solve(intervals, j, k - 1);

        Node take;
        take.score = temp.score + weight;
        take.idxs = temp.idxs;

        take.idxs.push_back(idx);

        // Keep indices sorted for lexicographical comparison
        sort(take.idxs.begin(), take.idxs.end());

        // Choose the better result
        Node result;

        if (skip.score > take.score) {
            result = skip;
        }
        else if (skip.score < take.score) {
            result = take;
        }
        else {
            // Same score -> lexicographically smaller indices
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return t[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        // Add original index
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort by starting position
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        // Calculate nextIdx for every interval
        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {

            int right = intervals[i][1];

            int lo = i + 1;
            int hi = n;

            // Find first interval with left > right
            while (lo < hi) {

                int mid = lo + (hi - lo) / 2;

                if (intervals[mid][0] > right) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }

            nextIdx[i] = lo;
        }

        // DP table
        // k = 0,1,2,3,4
        t.assign(n, vector<Node>(5));

        // We need score = -1 to indicate "not calculated"
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= 4; k++) {
                t[i][k].score = -1;
            }
        }

        // At most 4 intervals
        return solve(intervals, 0, 4).idxs;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}};
    vector<int> result = s.maximumWeight(intervals);
    cout << "Selected interval indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;

}