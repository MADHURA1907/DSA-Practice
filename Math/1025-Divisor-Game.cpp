#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};

int main()
{
    Solution s;
    cout<<s.divisorGame(3)<<endl;
    return 0;
}