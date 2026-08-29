#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for(int i=0;i<intervals.size()-1;i++)
        {
                if((intervals[i][1]>=intervals[i+1][0]))
                {
                    intervals[i][1]=max(intervals[i][1],intervals[i+1][1]);
                    intervals.erase(intervals.begin()+(i+1));
                    i--;
                }
        }
        return intervals;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = sol.merge(intervals);

    cout << "Merged intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}