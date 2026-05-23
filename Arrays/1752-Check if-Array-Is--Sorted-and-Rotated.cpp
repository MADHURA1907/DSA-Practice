#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {

        vector<int> duplicate(nums.size());

        for(int j = 0; j < nums.size(); j++) {

            for(int i = 0; i < nums.size(); i++) {
                duplicate[i] = nums[(i + j) % nums.size()];
            }

            bool b = true;

            for(int i = 0; i < nums.size() - 1; i++) {

                if(duplicate[i] > duplicate[i + 1]) {
                    b = false;
                    break;
                }
            }

            if(b == true) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2, 1, 3, 4};

    if(obj.check(nums)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}