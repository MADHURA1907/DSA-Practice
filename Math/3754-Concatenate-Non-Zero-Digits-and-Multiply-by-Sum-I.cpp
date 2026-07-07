#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        string x="0";
        string n1=to_string(n);
        int sum=0;
        for(int i=0;i<n1.length();i++)
        {
            if(n1[i]=='0')
            {
                continue;
            }
            else
            {
                x+=n1[i];
                sum+=(n1[i]-'0');
            }
        }
        return stoll(x) * sum;
        
    }
};

int main()
{
    Solution obj;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long result = obj.sumAndMultiply(n);
    cout << "The result of the operation is: " << result << endl;

    return 0;
}
