#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map <int,int> freq;
        for(auto x:nums)
        {
            freq[x]++;
        }

        // Sort
    sort(nums.begin(), nums.end(), [&](int a, int b) {
        if (freq[a] != freq[b])
            return freq[a] < freq[b];   // increasing frequency

        return a > b;                   // decreasing value
    });

    return nums;




    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 2, 3};
    vector<int> result = sol.frequencySort(nums);

    cout << "Sorted by frequency: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}