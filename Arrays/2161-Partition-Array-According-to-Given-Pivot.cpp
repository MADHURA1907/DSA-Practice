#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int i=0,j=nums.size()-1;
        vector<int> small;
        vector<int> large;
        vector<int> same;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
                small.push_back(nums[i]);
            }
            else if(nums[i]>pivot)
            {
                large.push_back(nums[i]);
            }
            else
            {
                same.push_back(nums[i]);
            }
        }
        for(int i=0;i<same.size();i++)
        {
            small.push_back(same[i]);
        }
        for(int i=0;i<large.size();i++)
        {
            small.push_back(large[i]);
        }
        return small;
        
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;
    
    vector<int> result = obj.pivotArray(nums, pivot);
    
    cout << "Pivoted Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}