#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long digits=1;
        long long count=9;
        long long a=count;
        while(n>a)
        {
            count *=10;
            digits++;
            a+=count*digits;
        }
        a-=count*digits;
        int r=n-a;
        r=r-1;
        int r1=r/digits;
        int N = pow(10,digits-1)+r1;
        string s=to_string(N);
        return (s[r%digits]-'0');
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = obj.findNthDigit(n);
    cout << "The " << n << "-th digit in the sequence is: " << result << endl;

    return 0;
}