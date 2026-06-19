#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int bsearch(vector<int>& nums,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>target)
            {
                return bsearch(nums,low,mid-1,target);
            }
            else if(nums[mid]<target)
            {
                return bsearch(nums,mid+1,high,target);
            }
            else 
            {
                if(mid==0 || nums[mid-1]!=nums[mid])
                {
                    return mid;
                }
                else
                {
                    return bsearch(nums,low,mid-1,target);
                }
            }
        }
         return -1;
    }

    int btwo(vector<int>& nums,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>target)
            {
                return btwo(nums,low,mid-1,target);
            }
            else if(nums[mid]<target)
            {
                return btwo(nums,mid+1,high,target);
            }
            else 
            {
                if(mid==nums.size()-1 || nums[mid]!=nums[mid+1])
                {
                    return mid;
                }
                else
                {
                    return btwo(nums,mid+1,high,target);
                }
            }
        }
         return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        vector<int> result;
        int f=bsearch(nums,low,high,target);
        int s=btwo(nums,low,high,target);
        result.push_back(f);
        result.push_back(s);
        return result;
        
    }
};

int main()
{
    Solution obj;
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> result=obj.searchRange(nums,target);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}