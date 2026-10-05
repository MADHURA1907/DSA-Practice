#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(string &s, int l, int r)
    {
        int score = 0;

        int i = l;

        while(i <= r)
        {
            // "()"
            if(s[i] == '(' && s[i+1] == ')')
            {
                score += 1;
                i += 2;
            }
            else
            {
                // Find matching ')'
                int count = 0;
                int j = i;

                for(; j <= r; j++)
                {
                    if(s[j] == '(')
                        count++;

                    else
                        count--;

                    if(count == 0)
                        break;
                }

                // s[i ... j] is (A)
                score += 2 * solve(s, i + 1, j - 1);

                i = j + 1;
            }
        }

        return score;
    }

    int scoreOfParentheses(string s)
    {
        return solve(s, 0, s.length() - 1);
    }
};

int main()
{
    Solution s;
    cout<<s.scoreOfParentheses("()")<<endl;
    cout<<s.scoreOfParentheses("(())")<<endl;
    return 0;
}