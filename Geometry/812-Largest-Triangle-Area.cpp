#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        int area=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int x1=points[i][0],y1=points[i][1];
                    int x2=points[j][0],y2=points[j][1];
                    int x3=points[k][0],y3=points[k][1];

                    int a=abs(x1*(y2-y3)-y1*(x2-x3)+1*((x2*y3)-(y2*x3)));
                    a=a/2;
                    if(a>area)
                    {
                        area=a;
                    }
                }
            }
        }
        return area;

        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{0,0}, {0,1}, {1,0}, {0,2}, {2,0}};
    cout << sol.largestTriangleArea(points) << endl;
    return 0;
}