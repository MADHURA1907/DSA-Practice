#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool b;
        if((n&1)!=0)
        {
            b=true;
        }
        else
        {
            b=false;
        }

        while(n!=0)
        {
            n=n>>1;
            if((n&1)!=0)
            {
                if(b!=false)
                {
                    return false;
                }
                b=true;
            }
            else
            {
                if(b!=true)
                {
                    return false;
                }
                b=false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    int n = 5; // Binary: 101
    bool result = sol.hasAlternatingBits(n);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}