#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        vector<int> suffix(nums.size(),1);
        vector<int> answer(nums.size());
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]= prefix[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            suffix[i]= suffix[i+1]*nums[i+1];
        }

        for(int i=0;i<nums.size();i++)
        {
            answer[i]=prefix[i]*suffix[i];
        }

        vector<int>().swap(prefix);
        vector<int>().swap(suffix);

        return answer;        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> result = sol.productExceptSelf(nums);      
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}