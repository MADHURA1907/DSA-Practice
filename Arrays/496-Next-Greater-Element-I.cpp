#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());

        for(int i = 0; i < nums1.size(); i++) {
            bool found = false;

            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {   
                    for(int k = j + 1; k < nums2.size(); k++) {
                        if(nums2[k] > nums2[j]) {
                            ans[i] = nums2[k];
                            found = true;
                            break;
                        }
                    }
                    break;
                }
            }

            if(!found) ans[i] = -1;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> ans = s.nextGreaterElement(nums1, nums2);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}