#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = 0;
        char x = '+';

        for (int i = 0; i < s.length(); i++) {

            if (isdigit(s[i])) {
                n = n * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) {

                if (x == '+') {
                    st.push(n);
                }
                else if (x == '-') {
                    st.push(-n);
                }
                else if (x == '*') {
                    int tempo = st.top();
                    st.pop();
                    st.push(tempo * n);
                }
                else if (x == '/') {
                    int tempo = st.top();
                    st.pop();
                    st.push(tempo / n);
                }

                x = s[i];
                n = 0;
            }
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "3+2*2";
    cout << sol.calculate(s) << endl;
    return 0;
}