#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int low = 0, high = numbers.size() - 1;

        while (low <= high) {
            if ((numbers[low] + numbers[high]) < target) {
                low++;
            }
            else if ((numbers[low] + numbers[high]) > target) {
                high--;
            }
            else {
                result.push_back(low + 1);
                result.push_back(high + 1);
                break;
            }
        }

        return result;
    }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> result = obj.twoSum(numbers, target);

    cout << "Indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}