#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> result;

    bool isvalid(string s)
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }

    void solve(string& curr,int n)
    {
        if(curr.length() == 2*n)
        {
            if(isvalid(curr))
            {
                result.push_back(curr);
            }
            return ;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr,n);
        return result;
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(3);
    for(int i=0;i<s.result.size();i++)
    {
        cout<<s.result[i]<<endl;
    }
    return 0;
}