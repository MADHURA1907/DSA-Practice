#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long mod = 1e9 + 7;
        int n = s.size();

        vector<long long> prefixNumber(n + 1, 0);
        vector<long long> prefixSum(n + 1, 0);
        vector<int> prefixCount(n + 1, 0);
        vector<long long> power10(n + 1, 1);

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            prefixNumber[i + 1] = prefixNumber[i];
            prefixSum[i + 1] = prefixSum[i];
            prefixCount[i + 1] = prefixCount[i];

            if (digit != 0) {
                prefixNumber[i + 1] =
                    (prefixNumber[i] * 10 + digit) % mod;

                prefixSum[i + 1] += digit;
                prefixCount[i + 1]++;
            }

            power10[i + 1] = (power10[i] * 10) % mod;
        }

        vector<int> answer;

        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];

            long long sum = prefixSum[r + 1] - prefixSum[l];

            int count = prefixCount[r + 1] - prefixCount[l];

            long long x = (
                prefixNumber[r + 1] -
                prefixNumber[l] * power10[count] % mod +
                mod
            ) % mod;

            long long result = (x * sum) % mod;

            answer.push_back(result);
        }

        return answer;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> queries={{0,7},{1,3},{4,6}};
    vector<int> ans = s.sumAndMultiply("10203004",queries);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}