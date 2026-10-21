#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Minimum character appears before the last position
        // OR maximum character appears after the first position
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Check whether minimum occurs in a proper prefix
        // or maximum occurs in a proper suffix
        bool minPrefix = false;
        bool maxSuffix = false;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == mn) {
                minPrefix = true;
            }
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == mx) {
                maxSuffix = true;
            }
        }

        if (minPrefix || maxSuffix) {
            return 2;
        }

        // If the string has at least 3 characters,
        // it can be sorted in 3 operations.
        if (n >= 3) {
            return 3;
        }

        return -1;
    }
};


int main()
{
    Solution s;
    cout<<s.minOperations("cba");
}