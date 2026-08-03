#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);

        int moves = 0;
        long long sum = 0;

        while (sum < target || (sum - target) % 2 != 0) {
            moves++;
            sum += moves;
        }

        return moves;
    }
};


int main()
{
    Solution s;
    cout << s.reachNumber(3) << endl;
    cout << s.reachNumber(2) << endl;
    return 0;
}