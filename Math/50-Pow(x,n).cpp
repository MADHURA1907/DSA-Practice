#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
    }
};

int main() {
    Solution obj;
    double x = 2.00000;
    int n = 10;
    cout << obj.myPow(x, n) << endl;

    return 0;
}