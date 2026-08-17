#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());
        int n= *max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies>=n)
            {
                result[i]=true;
            }
            else
            {
                result[i]=false;
            }
        }

        return result;
        
    }
};

int main()
{
    vector<int> candies={2,3,5,1,3};
    int extraCandies=3;
    Solution s;
    vector<bool> result=s.kidsWithCandies(candies,extraCandies);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}