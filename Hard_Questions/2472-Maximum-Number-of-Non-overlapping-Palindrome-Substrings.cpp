#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string&s, int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    int solve(string& s,int k,int i,int j,vector<vector<int>>& t)
    {
        int n=s.length();
        if(i>=n || j>=n)
        {
            return 0;
        }

        if(t[i][j] != -1)
        {
            return t[i][j];
        }
        if(isPalindrome(s,i,j))
        {
            int take = 1+solve(s,k,j+1,j+k,t);
            int grow = solve(s,k,i,j+1,t);
            int slide = solve(s,k,i+1,j+1,t);
            return t[i][j] = max({take,grow,slide});
        }

        int grow = solve(s,k,i,j+1,t);
        int slide = solve(s,k,i+1,j+1,t);

        return t[i][j] = max(grow,slide);
    }

    int maxPalindromes(string s, int k) {

        int n=s.length();
        vector<vector<int>> t(n+1,vector<int> (n+1,-1));
        if(k==1)
        {
            return n;
        }
        return (solve(s,k,0,k-1,t));
    }
};

int main()
{
    Solution sol;
    cout << sol.maxPalindromes("abccba", 3) << endl; // Output: 2
    return 0;
}