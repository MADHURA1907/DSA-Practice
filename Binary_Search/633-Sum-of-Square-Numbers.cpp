#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==1)
        {
            return true;
        }
        long long low=0,high=sqrt(c);
        while(low<=high)
        {
            long long sum=low*low+high*high;
            if(sum==c)
            {
                return true;
            }
            if(sum<c)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    bool b=s.judgeSquareSum(5);
    if(b)
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}