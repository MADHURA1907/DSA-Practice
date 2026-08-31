#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map <int,int> freq;

        for(auto x: nums)
        {
            freq[x]++;
        }

        int sum=0;

        for(auto x:freq)
        {
            if(x.second%k==0)
            {
                sum += (x.first*x.second);
            }
        }

        return sum;
    }

};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 2, 4, 6};
    int k = 2;
    int result = sol.sumDivisibleByK(nums, k);
    cout << "Sum of elements divisible by " << k << ": " << result << endl;

    return 0;
}