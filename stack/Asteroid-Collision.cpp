#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            bool destroyed = false;

            while(!s.empty() && s.top() > 0 && curr < 0) {
                if(abs(s.top()) < abs(curr)) {
                    s.pop(); // stack asteroid destroyed
                }
                else if(abs(s.top()) == abs(curr)) {
                    s.pop(); // both destroyed
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true; // current destroyed
                    break;
                }
            }

            if(!destroyed) {
                s.push(curr);
            }
        }

        vector<int> result(s.size());
        for(int i = s.size() - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = s.asteroidCollision(asteroids);

    for(int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}