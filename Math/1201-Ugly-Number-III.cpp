#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);

        long long abc = lcm(ab, c);

        long long low = 1;
        long long high = 2e9;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long count = mid / a + mid / b + mid / c
                            - mid / ab - mid / bc - mid / ac
                            + mid / abc;

            if (count >= n) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};


int main()
{
    Solution s;
    cout<<s.nthUglyNumber(3, 2, 3, 5)<<endl;
}