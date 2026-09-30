#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                depth++;
                ans.push_back(depth % 2);
            } 
            else {
                ans.push_back(depth % 2);
                depth--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> ans = s.maxDepthAfterSplit("((()))");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}