#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++)
        {
             if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
        }
        return s;
    }
};

int main() {
    Solution obj;
    string input = "Hello, World!";
    string result = obj.toLowerCase(input);
    
    cout << "Lowercase String: " << result << endl;

    return 0;
}