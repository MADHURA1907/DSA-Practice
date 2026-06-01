#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    string reverseVowels(string s) {
        string vowel = "";

        for(int i=0; i<s.size(); i++)
        {
            if(isVowel(s[i]))
                vowel += s[i];
        }

        int j = vowel.size() - 1;

        for(int i=0; i<s.size(); i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = vowel[j];
                j--;
            }
        }

        return s;
    }
};

int main()
{
    Solution obj;

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    cout << "String after reversing vowels: "
         << obj.reverseVowels(s) << endl;

    return 0;
}