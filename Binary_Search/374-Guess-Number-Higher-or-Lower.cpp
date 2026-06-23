#include <iostream>
using namespace std;

// Simulating the picked number
int picked = 6;

/**
 * @param num your guess
 * @return -1 if num is higher than the picked number
 *          1 if num is lower than the picked number
 *          0 if num is equal to the picked number
 */
int guess(int num) {
    if (num > picked)
        return -1;
    else if (num < picked)
        return 1;
    else
        return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int res = guess(mid);

            if (res == 0)
                return mid;
            else if (res == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};

int main() {
    int n = 10;

    Solution obj;
    cout << "Picked Number = " << obj.guessNumber(n) << endl;

    return 0;
}