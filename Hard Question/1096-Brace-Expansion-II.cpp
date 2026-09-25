#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<string> merge(set<string>& A, set<string>& B) {
        set<string> result;

        for (string a : A) {
            for (string b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    set<string> parse(string& s, int& i) {
        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {
            if (s[i] == '{') {
                i++;
                set<string> inside = parse(s, i);
                current = merge(current, inside);
                i++;
            }
            else if (s[i] == ',') {
                result.insert(current.begin(), current.end());
                current = {""};
                i++;
            }
            else {
                set<string> letter = {string(1, s[i])};
                current = merge(current, letter);
                i++;
            }
        }

        result.insert(current.begin(), current.end());
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};

int main() {
    Solution sol;

    string expression;
    cin >> expression;

    vector<string> ans = sol.braceExpansionII(expression);

    for (string s : ans) {
        cout << s << " ";
    }

    return 0;
}