#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int leftMax = nums[0];
        int globalMax = nums[0];
        int partitionIdx = 0;

        for (int i = 1; i < nums.size(); i++) {
            globalMax = max(globalMax, nums[i]);

            if (nums[i] < leftMax) {
                partitionIdx = i;
                leftMax = globalMax;
            }
        }

        return partitionIdx + 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums={5,0,3,8,6};
    cout<<"length of left: "<<s.partitionDisjoint(nums);
    return 0;

}