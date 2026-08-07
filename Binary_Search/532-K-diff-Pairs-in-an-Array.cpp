#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        sort(nums.begin(), nums.end());

        int low = 0, high = 1;
        int count = 0;

        while (high < nums.size()) {

            if (low == high) {
                high++;
                continue;
            }

            int diff = nums[high] - nums[low];

            if (diff < k) {
                high++;
            }
            else if (diff > k) {
                low++;
            }
            else {
                count++;
                low++;
                high++;

                while (high < nums.size() && nums[high] == nums[high - 1])
                    high++;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 1;
    int result = s.findPairs(nums, k);
    cout << result << endl;
    return 0;
}