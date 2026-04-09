#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    bool isThree(int n) {
        int root = sqrt(n);
        
        // check perfect square
        if (root * root != n) return false;
        
        // check if root is prime
        return isPrime(root);
    }
};

int main() {
    Solution s;
    int n = 9;
    cout << s.isThree(n) << endl; // Output: true
    return 0;
}