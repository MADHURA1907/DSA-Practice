#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(n%(i+1)==0)
            {
                sum += (nums[i]*nums[i]);
            }
        }

        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.sumOfSquares({1,2,3,4,5}) << endl;

}