#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int x=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='V')
            {
                x+=5;
            }
            else if(s[i]=='X')
            {
                if(i+1<s.length() && (s[i+1]=='L'||s[i+1]=='C'))
                {
                    x=x-10;
                }
                else
                {
                    x+=10;
                }
            }
            else if(s[i]=='L')
            {
                x+=50;
            }
            else if(s[i]=='C')
            {
                if(i+1<s.length() && (s[i+1]=='D'||s[i+1]=='M'))
                {
                    x=x-100;
                }
                else
                {
                    x+=100;
                }
            }
            else if(s[i]=='D')
            {
                x+=500;
            }
            else if(s[i]=='M')
            {
                x+=1000;
            }
            else if(s[i]=='I')
            {
                if(i+1<s.length() && (s[i+1]=='V'||s[i+1]=='X'))
                {
                    x=x-1;
                }
                else
                {
                    x+=1;
                }
            }
        }
        return x;
    }
};

int main()
{
    Solution s;
    cout<<s.romanToInt("MCMXCIV");
    return 0;
}