#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    bool check(int num)
    {
        while(num > 0)
        {
            if(num % 10 == 0)
            {
                return false;
            }
            num /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++)
        {
            int a = i;
            int b = n - i;

            if(check(a) && check(b))
            {
                return {a, b};
            }
        }

        return {};
    }
};

int main()
{
    Solution s;
    vector<int> result = s.getNoZeroIntegers(19);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}