#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        return min(360-abs((5.5*minutes)-(30*hour)),abs((5.5*minutes)-(30*hour)));
    }
};

int main() {
    Solution obj;
    cout << obj.angleClock(12, 30) << endl;
    cout << obj.angleClock(3, 30) << endl;
    cout << obj.angleClock(3, 15) << endl;

    return 0;
}