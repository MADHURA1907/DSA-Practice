#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum_element(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int m = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = sum_element(nums[i]);
            m = min(m, nums[i]);
        }

        return m;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.minElement(nums) << endl;

    return 0;
}