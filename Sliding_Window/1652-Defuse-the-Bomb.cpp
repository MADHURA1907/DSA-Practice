#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            return ans;
        }

        if (k > 0) {
            int sum = 0;

            // Initial window
            for (int j = 1; j <= k; j++) {
                sum += code[j % n];
            }

            for (int i = 0; i < n; i++) {
                ans[i] = sum;

                // Slide window
                sum -= code[(i + 1) % n];
                sum += code[(i + k + 1) % n];
            }
        }
        else {
            int x = -k;
            int sum = 0;

            for (int j = 1; j <= x; j++) {
                sum += code[(n - j) % n];
            }

            for (int i = 0; i < n; i++) {
                ans[i] = sum;

                sum -= code[(i - x + n) % n];
                sum += code[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> code = {5, 7, 1, 4};
    int k = 3;
    vector<int> result = s.decrypt(code, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}   