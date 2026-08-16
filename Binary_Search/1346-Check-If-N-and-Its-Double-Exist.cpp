#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int low=0,high=arr.size()-1;
        while(low<high)
        {
            if(arr[high] == 2*arr[low])
            {
                return true;
            }
            else if(arr[high]>2*arr[low])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> arr={10,2,5,3};
    Solution s;
    cout<<s.checkIfExist(arr)<<endl;
}