#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map <int,int> freq;
        while(n!=0)
        {
            int x=n%10;
            freq[x]++;
            n=n/10;
        }

        int s=INT_MAX;
        int f=-1;
        for(auto x: freq)
        {
            if(x.second<s)
            {
                s=x.second;
                f=x.first;
            }
            else if(x.second==s)
            {
                if(x.first<f)
                {
                    s=x.second;
                    f=x.first;
                }
            }
        }


 return f;

    }
};

int main()
{
    Solution sol;
    int n = 1223334444;
    int leastFrequentDigit = sol.getLeastFrequentDigit(n);
    cout << "Least Frequent Digit: " << leastFrequentDigit << endl;

    return 0;
}