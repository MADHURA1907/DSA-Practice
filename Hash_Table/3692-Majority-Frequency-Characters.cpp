#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq;

        for(char x : s)
        {
            freq[x]++;
        }

        unordered_map<int, string> groups;

        for(auto x : freq)
        {
            groups[x.second] += x.first;
        }

        int maximum_size = 0;
        int maximum_frequency = 0;
        string tempo = "";

        for(auto x : groups)
        {
            int group_size = x.second.size();
            int frequency = x.first;

            if(group_size > maximum_size ||
               (group_size == maximum_size && frequency > maximum_frequency))
            {
                maximum_size = group_size;
                maximum_frequency = frequency;
                tempo = x.second;
            }
        }

        return tempo;
    }
};


int main()
{
    Solution s;
    cout << s.majorityFrequencyGroup("aaabbbccddddeee") << endl;
    return 0;
}