#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> start(26, -1);
        vector<int> end(26, -1);

        // Find first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            if (start[c] == -1)
                start[c] = i;

            end[c] = i;
        }

        // Check which intervals are valid
        vector<bool> isValid(26, true);

        for (int c = 0; c < 26; c++) {
            if (start[c] == -1)
                continue;

            for (int i = start[c]; i <= end[c]; i++) {
                int x = s[i] - 'a';

                // Character appears before the current interval
                if (start[x] < start[c]) {
                    isValid[c] = false;
                    break;
                }

                // Expand the interval
                end[c] = max(end[c], end[x]);
            }
        }

        vector<string> result;

        // Greedy selection of non-overlapping intervals
        int lastTakenStart = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (!isValid[c])
                continue;

            if (i == start[c] && end[c] < lastTakenStart) {
                result.push_back(s.substr(i, end[c] - i + 1));
                lastTakenStart = i;
            }
        }

        // We selected from right to left, so reverse the answer
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    string s;

    cout << "Enter the string: ";
    cin >> s;

    Solution obj;

    vector<string> result = obj.maxNumOfSubstrings(s);

    cout << "Maximum non-overlapping substrings:\n";

    for (string str : result) {
        cout << str << " ";
    }

    cout << endl;

    return 0;
}