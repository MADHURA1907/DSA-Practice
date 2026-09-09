#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        if (n >= 1000) {
            ans += n - 1000 + 1;
        }

        if (n >= 1000000) {
            ans += n - 1000000 + 1;
        }

        if (n >= 1000000000) {
            ans += n - 1000000000 + 1;
        }

        if (n >= 1000000000000LL) {
            ans += n - 1000000000000LL + 1;
        }

        if (n >= 1000000000000000LL) {
            ans += n - 1000000000000000LL + 1;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    long long n = 1234567890123456; // Example input
    long long result = s.countCommas(n);
    cout << "Number of commas in numbers from 1 to " << n << ": " << result << endl;
    return 0;
}