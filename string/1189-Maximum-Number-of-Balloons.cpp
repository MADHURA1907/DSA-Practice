#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> balloon(5,0);
        for(int i=0;i<text.size();i++)
        {
            if(text[i]=='a')
            {
                balloon[1]++;
            }
            else if(text[i]=='b')
            {
                balloon[0]++;
            }
            else if(text[i]=='l')
            {
                balloon[2]++;
            }
            else if(text[i]=='o')
            {
                balloon[3]++;
            }
            else if(text[i]=='n')
            {
                balloon[4]++;
            }
        }

        balloon[2]=balloon[2]/2;
        balloon[3]=balloon[3]/2;
        int count=INT_MAX;
        for(int i=0;i<balloon.size();i++)
        {
            count = min(count,balloon[i]);
        }

        return count;
    }
};

int main() {
    Solution obj;
    string text = "nlaebolko";
    cout << obj.maxNumberOfBalloons(text) << endl;

    return 0;
}