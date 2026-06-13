#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int k=0;
        string result;
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            int sum=0;
            for(int j=0;j<s.size();j++)
            {
                char ch=s[j];
                int m=ch - 'a' ;
                sum += weights[m];
            }
            sum = sum%26;
            sum = 26-sum;
            char ch = 'a' + sum - 1;
            result += ch;
        }
        return result;
    }
};

int main() {
    Solution obj;
    vector<string> words = {"abc", "def"};
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 
                           14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 
                           25, 26};
    
    string result = obj.mapWordWeights(words, weights);
    
    cout << "Mapped Word Weights: " << result << endl;

    return 0;
}