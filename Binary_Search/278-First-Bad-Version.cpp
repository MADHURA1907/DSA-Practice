#include <iostream>
using namespace std;

// Simulating the API
int firstBad = 4;   // Change this to test different cases

bool isBadVersion(int version) {
    return version >= firstBad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter total number of versions: ";
    cin >> n;

    cout << "First bad version is: " << obj.firstBadVersion(n) << endl;

    return 0;
}