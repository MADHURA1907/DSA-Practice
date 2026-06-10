#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int count_digit(int x)
    {
        int count=0;
        while(x!=0)
        {
            count ++;
            x=x/10;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int add=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count_digit(nums[i])%2==0)
            {
                add++;
            }
        }
        return add;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {12, 345, 2, 6, 7896};
    
    int result = obj.findNumbers(nums);
    
    cout << "Count of numbers with even number of digits: " << result << endl;

    return 0;
}