#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto& k : knowledge) {
            mp[k[0]] = k[1];
        }

        string ans;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(') {
                ans += s[i];
            } else {
                string key = "";
                i++;

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<vector<string>> knowledge(n, vector<string>(2));
    for (int i = 0; i < n; i++) {
        cin >> knowledge[i][0] >> knowledge[i][1];
    }

    string ans = sol.evaluate(s, knowledge);
    cout << ans << endl;

    return 0;
}