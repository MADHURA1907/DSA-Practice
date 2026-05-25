#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int result = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size(); i++) {

            for(int j = i + 1; j < nums.size(); j++) {

                for(int k = j + 1; k < nums.size(); k++) {

                    int currentSum = nums[i] + nums[j] + nums[k];

                    if(abs(target - currentSum) < abs(target - result)) {
                        result = currentSum;
                    }
                }
            }
        }

        return result;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << obj.threeSumClosest(nums, target);

    return 0;
}