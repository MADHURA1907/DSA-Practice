#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int gcd(int a, int b)
    {
        while(b!=0)
        {
            int r= b%a;
            a=b;
            b=r;
        }
        return a;
    }

    int lcm(long long a, long long b)
    {
        return (a / gcd(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int max_length = 1;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            int gcd_value = 0;
            long long lcm_value = 1;

            for (int j = i; j < n; j++) {

                if (product > 1e10 / nums[j])
                    break;

                product *= nums[j];

                gcd_value = gcd(gcd_value, nums[j]);

                lcm_value = lcm(lcm_value, (long long)nums[j]);

                if (product == lcm_value * gcd_value) {
                    max_length = max(max_length, j - i + 1);
                }
            }
        }

        return max_length;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 3, 4, 6};
    cout << s.maxLength(nums) << endl;
    return 0;
}