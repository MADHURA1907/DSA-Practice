#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    for(int k = j + 1; k < nums.size(); k++) {
                        if(nums[j] == nums[k]) {
                            int dist = abs(i - j) + abs(j - k) + abs(k - i);
                            ans = min(ans, dist);
                        }
                    }
                }
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