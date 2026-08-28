#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> freq;
        for(char x:s)
        {
            freq[x]++;
        }

        vector<pair<char, int>> v(freq.begin(), freq.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans = "";

        for (auto &p : v) {
            ans += string(p.second, p.first);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "tree";
    string result = sol.frequencySort(s);

    cout << "Sorted string by frequency: " << result << endl;

    return 0;
}