#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(int i=0;i<patterns.size();i++)
        {
            string s=patterns[i];
            if (word.find(s) != string::npos)
            {
                count++;
            }
        }  
        return count;    
    }
};

int main()
{
    Solution s;
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";
    int result = s.numOfStrings(patterns, word);
    cout << result << endl;
    return 0;
}