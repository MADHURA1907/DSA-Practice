#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int i=10;
        bool b=false;
        while(i<=n)
        {
            n -= i;
            i--;
            if(b)
            {b=false;}
            else
            {
                b=true;
            }
        }
        return b;
    }
};

int main() {
    Solution s;
    int n = 20; // Example input
    bool result = s.canAliceWin(n);
    cout << "Can Alice win with " << n << " stones? " << (result ? "Yes" : "No") << endl;
    return 0;
}