#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;

        for(int i = 1; i <= num / 2; i++) {
            if(num % i == 0) {
                sum += i;
            }
        }

        if(num == sum) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution obj;

    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(obj.checkPerfectNumber(num)) {
        cout << num << " is a Perfect Number";
    }
    else {
        cout << num << " is NOT a Perfect Number";
    }

    return 0;
}