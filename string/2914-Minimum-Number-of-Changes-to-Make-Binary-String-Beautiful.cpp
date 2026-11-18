#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int count=0;

        for(int i=0;i<s.length();i+=2)
        {
            int sl0=0, sl1=0;

            if(s[i]=='0')
                sl0++;
            else
                sl1++;

            if(s[i+1]=='0')
                sl0++;
            else
                sl1++;

            if(sl0<=sl1)
                count+=sl0;
            else
                count+=sl1;
        }

        return count;
    }
};

int main()
{
    Solution sol;
    string s = "010101";
    cout << sol.minChanges(s) << endl;
    return 0;
}