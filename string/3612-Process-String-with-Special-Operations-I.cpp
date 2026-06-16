#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result="";
        string r;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                char ch=s[i];
                string temp="";
                temp += ch;
                result.append(temp);
            }
            else if(s[i]=='*')
            {
                if(!result.empty())
                {result.pop_back();}
            }
            else if(s[i]=='#')
            {
                r=result;
                result += r;
            }
            else if(s[i]=='%')
            {
                reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};

int main() {
    Solution obj;
    string s = "a#b*c%";
    string result = obj.processStr(s);
    cout << "Processed String: " << result << endl;
    return 0;
}