#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map <int,int> freq;
        while(n!=0)
        {
            int a=n%10;
            freq[a]++;
            n=n/10;
        }
        int sum=0;

        for(auto x:freq)
        {
            sum += x.first*x.second;
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    int n = 122333;
    int score = sol.digitFrequencyScore(n);
    cout << "Digit Frequency Score of " << n << " is: " << score << endl;

    return 0;
}