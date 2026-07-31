#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,high=arr.size(),mid=0;;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])
            {
                break;
            }

            if(arr[mid]<arr[mid+1])
            {
                low++;
            }
            else
            {
                high--;
            }

        }
        return mid;
    }
};

int main()
{
    Solution s;
    vector<int> arr={1,2,3,4,2,1};
    cout<<s.peakIndexInMountainArray(arr)<<endl;
}