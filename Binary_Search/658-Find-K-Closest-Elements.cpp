#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size() - 1;

        while (high - low + 1 > k) {
            if (abs(arr[low] - x) > abs(arr[high] - x))
                low++;      // remove left
            else
                high--;     // remove right
        }

        return vector<int>(arr.begin() + low, arr.begin() + high + 1);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Solution s;
    vector<int> ans = s.findClosestElements(arr, 4, 3);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}