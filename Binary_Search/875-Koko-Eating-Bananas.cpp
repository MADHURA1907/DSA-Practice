#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;

            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    Solution s;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int result = s.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}