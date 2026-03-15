/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        vector<int> result(nums1.size() + nums2.size());
        for(int i=0;i<n1;i++)
        {
            result[i]=nums1[i];
        }
        for(int i=0;i<n2;i++)
        {
            result[n1+i]=nums2[i];
        }
        sort(result.begin(),result.end());
        if((n)%2!=0)
        {return result[(n-1)/2];}
        else
        {return (result[(n-1)/2]+result[((n-1)/2)+1])/2.0;}
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}