#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateScore(int a, int b) {
        int x=a,y=b;
        int s1=0,s2=0;
        while(x!=0)
        {
            if(x%2==1)
            {
                s1++;
            }
            x=x/2;
        }

        while(y!=0)
        {
            if(y%2==1)
            {
                s2++;
            }
            y=y/2;
        }

        if(s1>=s2)
        {
            return s1*s2;
        }
        return s2/s1;
    }
};

int main()
{
    Solution s;
    cout<<s.calculateScore(12,15)<<endl;
}