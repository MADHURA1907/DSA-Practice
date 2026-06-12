#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        bool b=false;
        int count=0;
        int i;
        while(b==false)
        {
            for(i=0;i<nums.size()-1;i++)
            {
                if(nums[i]>nums[i+1])
                {
                    break;
                }
            }
            if(i==nums.size()-1)
            {
                return count;
            }
            int m=INT_MAX;
            int k;
            for(i=0;i<nums.size()-1;i++)
            {
                if(nums[i]+nums[i+1]<m)
                {
                    m=nums[i]+nums[i+1];
                    k=i;
                }
            }
            nums[k]=m;
            for(i=k+1;i<nums.size()-1;i++)
            {
                nums[i]=nums[i+1];
            }
            count++;

            nums.pop_back();
        }
        return count;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5};
    
    int result = obj.minimumPairRemoval(nums);
    
    cout << "Minimum Pair Removals: " << result << endl;

    return 0;
}