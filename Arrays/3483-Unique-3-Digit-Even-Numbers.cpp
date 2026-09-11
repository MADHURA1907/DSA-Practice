#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int freq[10] = {};

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        // Hundreds digit
        for (int h = 1; h <= 9; h++) {

            if (freq[h] == 0)
                continue;

            freq[h]--;

            // Tens digit
            for (int t = 0; t <= 9; t++) {

                if (freq[t] == 0)
                    continue;

                freq[t]--;

                // Units digit must be even
                for (int u = 0; u <= 8; u += 2) {

                    if (freq[u] > 0) {
                        ans++;
                    }
                }

                freq[t]++;
            }

            freq[h]++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> digits = {1, 2, 3, 4, 5};
    int result = s.totalNumbers(digits);
    cout << "Total even three-digit numbers: " << result << endl;
    return 0;
}