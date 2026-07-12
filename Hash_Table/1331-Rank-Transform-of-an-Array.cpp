#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> result;
        int r=1;
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map <int,int> rank;
        for(int x:temp)
        {
            if(rank.find(x)==rank.end())
            {
                rank[x]=r++;
            }
        }

        for(int x:arr)
        {
            result.push_back(rank[x]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {40, 10, 20, 30};
    vector<int> result = solution.arrayRankTransform(arr);
    for(int r : result) {
        cout << r << " "; // Output: 4 1 2 3
    }
    cout << endl;
    return 0;
}