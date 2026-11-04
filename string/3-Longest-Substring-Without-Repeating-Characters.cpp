#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int k=s.length();
        int i=0;
        int count=0;
        int ans =0;
        int m=0;
        for(int i=0;i<k;i++)
        {
            int j=i+1;
            while(s[i]!=s[j] && j<k)
            {
                j++;
            }
            if(j<k)
            {
                k=j;
            }
            if(i+1==k)
            {
                ans=max(ans,(k-m));
                k=s.length();
                count=0;
                m++;
                i=m-1;
            }

        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
    return 0;
}