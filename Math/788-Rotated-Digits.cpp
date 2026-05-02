#include <iostream>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for(int i = 1; i <= n; i++) {
            int a = i;
            bool valid = true;
            bool changed = false;

            while(a != 0) {
                int z = a % 10;

                if(z == 3 || z == 4 || z == 7) {
                    valid = false;
                    break;
                }

                if(z == 2 || z == 5 || z == 6 || z == 9) {
                    changed = true;
                }

                a /= 10;
            }

            if(valid && changed) {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
    cout<<s.rotatedDigits(10);
}