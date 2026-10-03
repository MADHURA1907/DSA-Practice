#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.length();

        int left  = 0;
        int right = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                left++;
            }
            else 
            {
                right++;
            }

            if(left==right)
            {
                ans=max(ans,left*2);
            }
            else if(right>left)
            {
                left=0;right=0;
            }
        }
        left=0;right=0;

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                left++;
            }
            else 
            {
                right++;
            }

            if(left==right)
            {
                ans=max(ans,left*2);
            }
            else if(right<left)
            {
                left=0;right=0;
            }
        }


        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.longestValidParentheses(")()())")<<endl;
    return 0;
}