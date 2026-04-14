#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i;
        int m=INT_MAX;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                m=min(m,abs(i - start));
            }
        }
        return m;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 3;
    int start = 0;
    int result = sol.getMinDistance(nums, target, start);
    cout << "Minimum distance: " << result << endl;
    return 0;
}