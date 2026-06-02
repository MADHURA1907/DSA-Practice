#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int count=0;
        int i=1;
        while(n-i>=0)
        {
            n=n-i;
            count++;
            i++;  
        }
        return count;
    }
};

int main()
{
    Solution s;
    int n=5;
    cout<<s.arrangeCoins(n)<<endl;;
    return 0;
}