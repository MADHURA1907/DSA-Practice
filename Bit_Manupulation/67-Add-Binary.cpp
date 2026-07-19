#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
       string result;
       int i=a.length()-1;
       int j=b.length()-1;
       int carry=0;
       while(i>=0 || j>=0 || carry!=0)
       {
            int x = (i >= 0) ? a[i] - '0' : 0;
            int y = (j >= 0) ? b[j] - '0' : 0;
            int sum=(x+y+carry)%2;
            carry=(x+y+carry)/2;
            result+= to_string(sum);
            i--;j--;
       }
         reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution s;
    string a = "11";
    string b = "1";
    string result = s.addBinary(a, b);
    cout << result << endl;
    return 0;
}