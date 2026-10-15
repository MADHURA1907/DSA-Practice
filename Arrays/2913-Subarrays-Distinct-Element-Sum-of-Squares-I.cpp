#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int count = 0;
        set<int> s;
        for (int i = 0; i < n; i++) {    
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) { 
                s.insert(nums[k]);
            }
            count+=(s.size()*s.size());
            s.clear();
        }
    }
    return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout<<s.sumCounts(nums); // Output: 14
    return 0;
}