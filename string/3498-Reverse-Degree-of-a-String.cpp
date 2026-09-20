#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            int value= (26-(ch-'a'))*(i+1);
            sum += value;
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    string s = "abc";
    int result = solution.reverseDegree(s);
    cout << result << endl;

    return 0;
}