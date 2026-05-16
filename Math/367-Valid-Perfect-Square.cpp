#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0 || num==1)
        {
            return true;
        }
        for(long long i=0;i<=num/2;i++)
        {
            if(i*i==num)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int num = 16;

    Solution obj;

    if(obj.isPerfectSquare(num))
    {
        cout << num << " is a perfect square." << endl;
    }
    else
    {
        cout << num << " is not a perfect square." << endl;
    }

    return 0;
}