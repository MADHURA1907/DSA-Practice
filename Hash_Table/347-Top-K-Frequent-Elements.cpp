#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;

        // Count frequency
        for(int x : nums)
        {
            freq[x]++;
        }

        vector<int> ans;

        while(k--)
        {
            int maxFreq = 0;
            int element = 0;

            // Find maximum frequency
            for(auto it = freq.begin(); it != freq.end(); it++)
            {
                if(it->second > maxFreq)
                {
                    maxFreq = it->second;
                    element = it->first;
                }
            }

            ans.push_back(element);

            // Remove it so we find the next maximum
            freq.erase(element);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}