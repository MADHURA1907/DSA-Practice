#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evensum=0,oddsum=0;
        for(int i=0;i<2*n;i++)
        {
            if(i%2==0)
            {
                evensum+= i;
            }
            else
            {
                oddsum+=i;
            }
        }
        return __gcd(evensum,oddsum);
    }
};

int main()
{
    Solution solution;
    int n = 5;
    int result = solution.gcdOfOddEvenSums(n);
    cout << "GCD of odd and even sums for n = " << n << " is: " << result << endl;
    return 0;
}