#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        int n=arr1.size();
        int m=arr2.size();
        int i;
        for(int j=0;j<n;j++)
        {
            for(i=0;i<m;i++)
            {
                if(abs(arr1[j]-arr2[i])<=d)
                {
                    break;
                }
            }
            if(i==m)
            {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> arr1={4,5,8};
    vector<int> arr2={10,9,1,8};
    cout<<s.findTheDistanceValue(arr1, arr2, 2);
    return 0;
}