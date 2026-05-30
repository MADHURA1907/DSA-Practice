#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;

        int total = 0;

        for(int i = 0; i < timeSeries.size() - 1; i++) {
            total += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }

        total += duration;

        return total;
    }
};

int main()
{
    Solution s;
    int duration=2;
    vector<int> timeSeries = {1,4};
    cout<<s.findPoisonedDuration(timeSeries,duration);
    return 0;
}
