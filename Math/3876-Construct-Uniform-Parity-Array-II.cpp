#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int mn = INT_MAX;

        for (int x : nums1) {
            mn = min(mn, x);

            if (x % 2 != 0)
                minOdd = min(minOdd, x);
        }

        for (int x : nums1) {
            if (x % 2 != mn % 2) {
                if (minOdd >= x)
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {2, 4, 6, 8};
    cout << (s.uniformArray(nums1) ? "true" : "false") << endl; // Output: true

    vector<int> nums2 = {2, 3, 4, 5};
    cout << (s.uniformArray(nums2) ? "true" : "false") << endl; // Output: false

    return 0;
}