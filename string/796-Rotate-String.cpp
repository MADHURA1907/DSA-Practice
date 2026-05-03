#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        string b;
        if(s.length()!=goal.length())
        {
            return false;
        }

        for(int i=0;i<s.length();i++)
        {
            char a=s[0];
            s=s.substr(1,s.length()-1);
            s=s+a;
            if(s==goal)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    if(s.rotateString("abcde","cdeab"))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

    return 0;
}
