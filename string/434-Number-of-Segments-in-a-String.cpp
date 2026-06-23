#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ' && (i==0 || s[i-1]==' '))
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    string s="Hello my name is madhura";
    Solution s1;
    cout<<s1.countSegments(s)<<endl;
    return 0;
}