#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        bool b=true;
        string result = "";
        while(i<word1.length() && j<word2.length())
        {
            if(b==true)
            {
                result += word1[i];
                i++;
                b=false;
            }
            else
            {
                result += word2[j];
                j++;
                b=true;
            }
        }

        while(i<word1.length())
        {
            result += word1[i++];
        }

        while(j<word2.length())
        {
            result += word2[j++];
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string word1 = "abc";
    string word2 = "pqr";
    string mergedString = sol.mergeAlternately(word1, word2);
    cout << "Merged String: " << mergedString << endl;

    return 0;
}