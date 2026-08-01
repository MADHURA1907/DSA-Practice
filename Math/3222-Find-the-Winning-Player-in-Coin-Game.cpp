#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string winningPlayer(int x, int y) {
        y=y/4;
        if(x<y)
        {
            if(x%2==0)
            {
                return "Bob";
            }
        }
        else
        {
            if(y%2==0)
            {
                return "Bob";
            }
        }
        return "Alice";
    }
};

int main()
{
    Solution s;
    int x,y;
    cin>>x>>y;
    cout<<s.winningPlayer(x,y)<<endl;
}