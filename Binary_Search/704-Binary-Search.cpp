#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int  mid=(low+high)/2;
            if(nums[mid]>target)
            {
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else 
            {
                return mid;
            }
        }
        return -1;
    }
};

int main()
{
    vector <int> arr({-1,0,3,5,9,12});
    int target=9;
    Solution s;
    int result= s.search(arr,target);
    cout<<result<<endl;
    
}