#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfCuts(int n) {
        int a=0;
        if(n==1)
        {
            return 0;
        }

        if(n%2==0)
        {
            a=n/2;
        }
        else 
        {
            a=n;
        }
        return a;
        
    }
};

int main() {
    Solution sol;
    int n = 4;
    cout << sol.numberOfCuts(n) << endl; 
    return 0;
}