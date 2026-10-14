#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        string ans = "";

        for (int i = 0; i < num; i++) {
            int digit = min(9, sum);
            ans += char('0' + digit);
            sum -= digit;
        }

        return ans;
    }
};

int main() {
    Solution s;
    int num = 3;
    int sum = 20;
    cout << s.maxSumOfSquares(num, sum) << endl; // Output: "992"
    return 0;
}