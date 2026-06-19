#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int a=0;
        int x=0;
        for(int i=0;i<gain.size();i++)
        {
            x=x+gain[i];
            a= max(a,x);
        }
        return a;
    }
};

int main() {
    Solution obj;
    vector<int> gain = {-5,1,5,0,-7};
    cout << obj.largestAltitude(gain) << endl;

    return 0;
}