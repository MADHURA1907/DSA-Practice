#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if(((points[1][1]-points[0][1])*(points[2][0]-points[0][0]))!=((points[2][1]-points[0][1])*(points[1][0]-points[0][0])))
        {
            return true;
        }

        return false;
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1,1},{2,3},{3,2}};
    bool result = sol.isBoomerang(points);      
    cout << result << endl;
    return 0;
}