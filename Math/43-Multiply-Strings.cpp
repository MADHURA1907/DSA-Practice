#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();

        vector<int> tempo(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                int mul = digit1 * digit2;
                int sum = mul + tempo[i + j + 1];

                tempo[i + j + 1] = sum % 10;
                tempo[i + j] += sum / 10;
            }
        }

        string result = "";

        for (int i = 0; i < tempo.size(); i++) {
            if (!result.empty() || tempo[i] != 0) {
                result += to_string(tempo[i]);
            }
        }

        return result.empty() ? "0" : result;
    }
};


int main()
{
    Solution s;
    cout << s.multiply("2", "3") << endl;
    return 0;
}