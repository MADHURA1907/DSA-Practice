#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (!isalpha(s[i])) {
                i++;
            }
            else if (!isalpha(s[j])) {
                j--;
            }
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};

int main() {
    Solution obj;
    string s = "ab-cd";
    cout << obj.reverseOnlyLetters(s) << endl;

    return 0;
}