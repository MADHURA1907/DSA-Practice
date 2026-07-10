#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.length()-1;
        int j=num2.length()-1;
        string result;
        int carry=0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    string num1 = "123";
    string num2 = "456";
    string result = solution.addStrings(num1, num2);
    cout << "Sum: " << result << endl; // Output: Sum: 579
    return 0;
}