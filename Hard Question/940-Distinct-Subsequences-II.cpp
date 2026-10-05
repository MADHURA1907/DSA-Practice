#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        long long total = 0;

        for(char ch : s)
        {
            int x = ch - 'a';

            long long newSubseq = (total + 1) % MOD;

            total = (total + newSubseq - dp[x] + MOD) % MOD;

            dp[x] = newSubseq;
        }

        return total;
    }
};

int main()
{
    Solution s;
    cout<<s.distinctSubseqII("abc")<<endl;
    cout<<s.distinctSubseqII("aba")<<endl;
    cout<<s.distinctSubseqII("aaa")<<endl;
    return 0;
}