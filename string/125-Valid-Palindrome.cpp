#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(int i=0;i<s.length();i++)
        {
            if(isalnum(s[i]))
            {
                s1+=tolower(s[i]);
            }   
        }
        int n=s1.length();
        for(int i=0;i<n/2;i++)
        {
        if(s1[i]!=s1[n-1-i])
        {
            return false;
        }
        }
        return true;

    }
};

int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(s);      
    cout << result << endl;
    return 0;
}