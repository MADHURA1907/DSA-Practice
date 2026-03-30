#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string e1="";
        string e2="";
        string o1="";
        string o2="";
        for(int i=0;i<s1.size();i++)
        {
            if(i%2==0)
            {
                e1.push_back(s1[i]);
            }
            else
            {
                o1.push_back(s1[i]);
            }
        }
        for(int i=0;i<s2.size();i++)
        {
            if(i%2==0)
            {
                e2.push_back(s2[i]);
            }
            else
            {
                o2.push_back(s2[i]);
            }
        }
        sort(e1.begin(),e1.end());
        sort(e2.begin(),e2.end());
        sort(o1.begin(),o1.end());
        sort(o2.begin(),o2.end());
        return (e1==e2 && o1==o2);
        
    }
};

int main()
{
    Solution s;
    string s1="abcd";
    string s2="cdab";
    cout<<s.checkStrings(s1,s2);
}