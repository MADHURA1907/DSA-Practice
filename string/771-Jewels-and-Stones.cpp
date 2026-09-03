#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        for(int i=0;i<stones.length();i++)
        {
            if(jewels.find(stones[i]) != string::npos)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    string jewels = "aA";
    string stones = "aAAbbbb";
    int count = sol.numJewelsInStones(jewels, stones);
    cout << "Number of Jewels in Stones: " << count << endl;

    return 0;
}