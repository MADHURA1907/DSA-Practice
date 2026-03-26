#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        while (i < n && s[i] == ' ') i++;
        
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        
        long long num = 0;
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            if (num > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            num = num * 10 + digit;
            i++;
        }
        
        return sign * num;
    }
};

int main() {
    Solution sol;
    string s = "   -42";
    int result = sol.myAtoi(s);
    cout << result << endl; // Output: -42
    return 0;
}