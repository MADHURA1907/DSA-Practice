#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        char curr;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else 
            {

                if(st.empty())
                    return false;

                    
                curr=st.top();
                st.pop();
                if(s[i]==')' && curr!='(')
                {
                    return false;
                }
                else if(s[i]=='}' && curr!='{')
                {
                    return false;
                }
                else if(s[i]==']' && curr!='[')
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution s;
    string str="()[]{}";
    if(s.isValid(str))
    {
        cout<<"Valid Parenthesis"<<endl;
    }
    else
    {
        cout<<"Invalid Parenthesis"<<endl;
    }
    
    return 0;
}