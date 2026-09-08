#include <iostream>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        
       return  ((n-1000+1)<0)?0:(n-1000+1);


    }
};

int main()
{
    Solution s;
    int n = 12345; // Example input
    int result = s.countCommas(n);
    cout << "Number of commas in numbers from 1 to " << n << ": " << result << endl;
    return 0;
}