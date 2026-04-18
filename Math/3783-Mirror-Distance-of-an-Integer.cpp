#include  <iostream>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int a=n;
        int reverse=0;
        while(a!=0)
        {
            reverse = reverse*10+a%10;
            a=a/10;
        }
        return abs(reverse-n);
        
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.mirrorDistance(n);
}