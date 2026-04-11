#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        // array of vectors instead of hashmap
        vector<vector<int>> pos(n + 1);
        
        // store indices
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        // process each value
        for (int val = 1; val <= n; val++) {
            auto &v = pos[val];
            
            if (v.size() < 3) continue;
            
            for (int i = 0; i + 2 < v.size(); i++) {
                int p = v[i];
                int r = v[i + 2];
                
                ans = min(ans, 2 * (r - p));
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    int result = sol.minimumDistance(nums);
    cout << "Minimum distance: " << result << endl;
    return 0;
}