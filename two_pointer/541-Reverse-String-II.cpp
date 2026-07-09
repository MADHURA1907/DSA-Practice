#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if((s.length()-i)>=2*k || (((s.length()-i)<2*k && (s.length()-i)>=k)))
            {
                reverse(s.begin()+i,s.begin()+i+k);
            }
            else if((s.length()-i)<k)
            {
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};

int main()
{
    string s="abcdefg";
    int k=2;
    Solution obj;
    cout<<obj.reverseStr(s,k)<<endl;
    return 0;
}