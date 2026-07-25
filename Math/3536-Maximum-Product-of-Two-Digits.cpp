#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        
        int k=0;
        vector<int> arr;
        while(n!=0)
        {
            arr.push_back(n%10);
            n=n/10;
        }
        int m=arr.size();
        sort(arr.begin(),arr.end());
        return arr[m-1]*arr[m-2];
    }
};

int main()
{
    Solution s;
    int n = 234;
    int result = s.maxProduct(n);
    cout << "Maximum Product of Two Digits: " << result << endl;
    return 0;
}