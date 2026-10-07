#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(string s) {
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
            }
            else if (ch == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;
        unordered_set<string> visited;

        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            string curr = q.front();
            q.pop();

            // If valid, add it to answer
            if (isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }

            // Once valid strings are found,
            // don't generate strings with more removals
            if (found)
                continue;

            // Generate next level
            for (int i = 0; i < curr.length(); i++) {

                // Only remove parentheses
                if (curr[i] != '(' && curr[i] != ')')
                    continue;

                string next = curr.substr(0, i) +
                              curr.substr(i + 1);

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.removeInvalidParentheses("()())()");
    for (string str : ans) {
        cout << str << endl;
    }

    return 0;
}