#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count=0;
        int leftb=0,rightb=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                leftb++;
            }
            else if(s[i]==')')
            {
            rightb++;
            }

            count=max(count,(leftb-rightb));
        }

        return count;

        
    }
};

int main()
{
    Solution s;
    string st="(1+(2*3)+((8)/4))+1";
    cout<<s.maxDepth(st);
}