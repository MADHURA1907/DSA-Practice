#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;

        int i = num.size() - 1;

        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i];
                i--;
            }

            result.insert(result.begin(), k % 10);
            k /= 10;
        }

        return result;
    }
};


int main()
{
    Solution s;
    vector<int> num = {1, 2, 0, 0};
    for(int i=0; i<s.addToArrayForm(num, 34).size(); i++) {
        cout<<s.addToArrayForm(num, 34)[i]<<" ";
    }
    return 0;
}