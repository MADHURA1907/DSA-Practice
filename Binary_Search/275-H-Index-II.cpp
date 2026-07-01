#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;

        if (citations[0] == 0 && n == 1) {
            return 0;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (citations[mid] >= n - mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return n - low;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of papers: ";
    cin >> n;

    vector<int> citations(n);

    cout << "Enter the sorted citation counts: ";
    for (int i = 0; i < n; i++) {
        cin >> citations[i];
    }

    cout << "H-Index = " << obj.hIndex(citations) << endl;

    return 0;
}