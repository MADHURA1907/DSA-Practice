#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string finalString(string s) {
        string ans = "";

        for(char ch : s) {
            if(ch == 'i') {
                reverse(ans.begin(), ans.end());
            } else {
                ans += ch;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s = "string";
    
    string result = obj.finalString(s);
    
    cout << "Final String: " << result << endl;

    return 0;
}