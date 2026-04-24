#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a=0;
        
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
            {
                a--;
            }
            else if(moves[i]=='R')
            {
                a++;
            }
            else 
            {
                a--;
            }
        }
        int b=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
            {
                b--;
            }
            else if(moves[i]=='R')
            {
                b++;
            }
            else 
            {
                b++;
            }
        }
        return max(abs(a),abs(b));
        
    }
};

int main()
{
    Solution s;
    string moves="L_RL__R";
    int a=s.furthestDistanceFromOrigin(moves);
    cout<<a;
    return 0;
}