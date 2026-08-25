#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int alength=INT_MAX;
        for(int i=0;i<strs.size();i++)
        {
            alength = (alength>strs[i].length())?strs[i].length():alength;
        }
        string result="";
        int i,j;
        for(i=0;i<alength;i++)
        {
            for(j=0;j<strs.size()-1;j++)
            {
                if(strs[j][i]==strs[j+1][i])
                {
                    continue;
                }
                else
                {
                    return result;
                }
            }
            result+=strs[j][i];
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> strs={"flower","flow","flight"};
    cout<<s.longestCommonPrefix(strs);
}