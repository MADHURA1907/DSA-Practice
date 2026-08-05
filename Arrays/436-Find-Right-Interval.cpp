#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> result(intervals.size(),-1);

        for(int j=0;j<intervals.size();j++)
        {
            int i,m=INT_MAX,idx=-1;
            for(i=0;i<intervals.size();i++)
            {
                if(intervals[j][1]<=intervals[i][0] && intervals[i][0]<m)
                {
                    m=intervals[i][0];
                    idx=i;
                }
            }
            result[j]=idx;
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> intervals={{3,4},{2,3},{1,2}};
    vector<int> result=s.findRightInterval(intervals);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}