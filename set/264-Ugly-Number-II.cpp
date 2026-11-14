#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> ans;
        ans.insert(1);

        long long u;

        for(int i = 0; i < n; i++)
        {
            u = *ans.begin();
            ans.erase(ans.begin());

            ans.insert(u * 2);
            ans.insert(u * 3);
            ans.insert(u * 5);
        }

        return u;
    }
};

int main()
{
    Solution s;
    int n = 10;
    cout << s.nthUglyNumber(n);
}