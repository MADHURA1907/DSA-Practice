#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {

            if(i > 0 && nums[i] == nums[i-1])
                {continue;}


            int low=i+1,high=nums.size()-1;
            while(low<high)
            {
                if(nums[i]+nums[low]+nums[high]==0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    result.push_back(temp);
                    temp.clear();
                    low++;
                    high--;

                    while(low < high && nums[low] == nums[low-1])
                        {low++;}

                    while(low < high && nums[high] == nums[high+1])
                        {high--;}
                }
                else if(nums[i]+nums[low]+nums[high]<0)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> result=s.threeSum(nums);

    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

}