#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int odd=INT_MIN;
        int even=INT_MAX;
        unordered_map <char,int> freq;
        for(auto x:s)
        {
            freq[x]++;
        }

        for(auto x:freq)
        {
            if(x.second%2==0)
            {
                if(even>x.second)
                {
                    even=x.second;
                }
            }
            else
            {
                if(odd<x.second)
                {
                    odd=x.second;
                }
            }
        }

        return (odd-even);
    }
};

int main()
{
    Solution sol;
    string s = "aabbccddeeffgghh";
    int result = sol.maxDifference(s);
    cout << "Max Difference: " << result << endl;

    return 0;
}