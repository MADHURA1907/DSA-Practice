#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int count=1;
        int z=0;
        for(int i=0;i<word.length()-1;i++)
        {
            if(word[i]==word[i+1])
            {
                z++;
            }
            else
            {
                count+=z;
                z=0;
            }
        }
        count+=z;
        return count;
        
    }
};

int main()
{
    Solution s;
    string word="aabb";
    cout<<s.possibleStringCount(word);
    return 0;
}