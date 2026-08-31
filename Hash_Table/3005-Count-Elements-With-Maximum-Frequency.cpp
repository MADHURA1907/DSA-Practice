#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map <int,int> freq;
        for(auto x: nums)
        {
            freq[x]++;
        }

        int result=0;
        int f=0;
        for(auto x:freq)
        {
            if(x.second>f)
            {
                f=x.second;
                result=f;
            }
            else if(x.second==f)
            {
                result+= f;
            }
        }

        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4};
    int result = sol.maxFrequencyElements(nums);
    cout << "Max Frequency Elements: " << result << endl;

    return 0;
}