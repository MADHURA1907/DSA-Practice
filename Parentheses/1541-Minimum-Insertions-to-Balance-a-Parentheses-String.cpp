#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        int close = 0;

        for (char c : s) {
            if (c == '(') {
                if (close % 2 == 1) {
                    count++;
                    close--;
                }
                close += 2;
            }
            else {
                close--;

                if (close < 0) {
                    count++;
                    close = 1;
                }
            }
        }

        return count + close;
    }
};

int main()
{
    Solution s;
    cout<<s.minInsertions("(()))(()))()())))")<<endl;
    return 0;
}