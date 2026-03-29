#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2)
        {
            return true;
        }
        string a=s1;
        string b=s2;
        for(int i=2;i<s1.size();i++)
        {
            swap(s1[i-2],s1[i]);
            if(s1==s2)
            {
                return true;
            }
            for(int i=2;i<s2.size();i++)
            {
                swap(s2[i-2],s2[i]);
            if(s1==s2)
            {
                return true;
            }
                s2=b;
            }
        }
       
        return false;

        
    }
};

int main() {
    Solution sol;
    string s1 = "abc";
    string s2 = "bca";
    bool result = sol.canBeEqual(s1, s2);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}