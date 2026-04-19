#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int left=0, right=0;
        int m=0;
        while(left<nums1.size() && right<nums2.size() )
        {
            if(nums1[left]<=nums2[right])
            {
                m=max(m,(right-left));
                right++;
            }
            else
            {
                left++;
            }
            
        }

        return m;
        
        
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n),nums2(m);
    for(int i=0;i<n;i++)
        cin>>nums1[i];
    for(int i=0;i<m;i++)
        cin>>nums2[i];
    cout<<s.maxDistance(nums1,nums2);
}