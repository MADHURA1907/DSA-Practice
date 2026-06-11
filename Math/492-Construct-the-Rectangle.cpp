#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);

        while (area % w != 0) {
            w--;
        }

        int l = area / w;

        return {l, w};
    }
};

int main() {
    Solution obj;
    int area = 4;
    
    vector<int> result = obj.constructRectangle(area);
    
    cout << "Length: " << result[0] << ", Width: " << result[1] << endl;

    return 0;
}