#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int l=0,d=0,u=0,r=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
            {
                l++;
            }
            else if(moves[i]=='R')
            {
                r++;
            }
            else if(moves[i]=='U')
            {
                u++;
            }
            else
            {
                d++;
            }
        }
    

    if(l==r && d==u)
    {
        return true;
    }
    return false;
    }
};

int main()
{
    Solution s;
    string moves="UD";
    cout<<s.judgeCircle(moves);
}