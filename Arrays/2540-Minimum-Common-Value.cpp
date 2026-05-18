#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
            else
            {
                return nums1[i];
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {5,6,7,8,9};

    int result = obj.getCommon(nums1, nums2);

    if(result != -1)
    {
        cout << "Common element: " << result << endl;
    }
    else
    {
        cout << "No common element found." << endl;
    }

    return 0;
}