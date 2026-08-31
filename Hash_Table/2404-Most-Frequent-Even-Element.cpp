#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map <int,int> freq;
        for(auto x:nums)
        {
            freq[x]++;
        }

        int f=-1;
        int s=-1;

        for(auto x:freq)
        {
            if(x.first%2==0 && s<x.second)
            {
                s=x.second;
                f=x.first;
            }
            else if(x.first%2==0 && s==x.second)
            {
                if(f>x.first)
                {
                    s=x.second;
                    f=x.first;
                }
            }
        }
        return f;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 2, 2, 4, 4, 1};
    int mostFrequentEvenNum = sol.mostFrequentEven(nums);
    cout << "Most Frequent Even Number: " << mostFrequentEvenNum << endl;

    return 0;
}