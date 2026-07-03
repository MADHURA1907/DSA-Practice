#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(letters[mid]<=target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(low>=n)
        {
            return letters[0];
        }
        return letters[low];
    }
};

int main() {
    Solution obj;

    int n;
    char target;
    cout << "Enter the number of letters: ";
    cin >> n;

    vector<char> letters(n);
    cout << "Enter the letters: ";
    for (int i = 0; i < n; i++) {
        cin >> letters[i];
    }

    cout << "Enter the target letter: ";
    cin >> target;

    char result = obj.nextGreatestLetter(letters, target);
    cout << "The next greatest letter after '" << target << "' is: " << result << endl;

    return 0;
}