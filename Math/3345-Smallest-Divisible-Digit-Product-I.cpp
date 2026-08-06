#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        int pro;
        do{
            int i = n;
            pro = 1;

            while(i > 0){
                pro *= (i % 10);
                i /= 10;
            }

            n++;
        } while(pro % t != 0);

        return n - 1;
    }
};

int main()
{
    Solution s;
    int n = 10, t = 5;
    int result = s.smallestNumber(n, t);
    cout << result << endl;
    return 0;
}