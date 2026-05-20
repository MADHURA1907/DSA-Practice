#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> result;

        vector<int> freq(nums.size(), 0);

        // Count frequency
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] - 1]++;
        }

        // Find missing numbers
        for(int i = 0; i < nums.size(); i++)
        {
            if(freq[i] == 0)
            {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};

    Solution obj;

    vector<int> ans = obj.findDisappearedNumbers(nums);

    cout << "Disappeared numbers are: ";

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}