#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int tempo = a ^ b;
            int carry = (a & b) << 1;

            a = tempo;
            b = carry;
        }

        return a;
    }
};

int main()
{
    Solution s;
    cout<<s.getSum(2,3)<<endl;
    return 0;
}