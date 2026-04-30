#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.length() && j<t.length())
        {
            if(s[i]==t[j])
            {
                i++;
            }
            j++;
        }
        if(i==s.length())
        {
            return true;
        }
        return false;
    }
};

int main(){
    Solution st;
    string s="abc";
    string t="ahbgdc";
    if(st.isSubsequence(s,t))
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

}