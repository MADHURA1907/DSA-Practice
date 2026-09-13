#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int count_overlap(vector<vector<int>>& img1, vector<vector<int>>& img2,int r,int c)
    {
        int n= img1.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int nr=i+r;
                int nc=j+c;
                if(nr>=0 && nr<n && nc>=0 && nc<n)
                {
                    if(img1[i][j]==1 && img2[nr][nc]==1)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }


    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int result=0;
        int n=img1.size();
        for(int row=(-1*n)+1 ; row<n ; row++)
        {
            for(int col = (-1*n)+1 ; col<n ; col++)
            {
                int a=count_overlap(img1,img2,row,col);
                result=max(result,a);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> img1={{1,1,0},{0,1,0},{0,1,0}};
    vector<vector<int>> img2={{0,0,0},{0,1,1},{0,0,1}};
    int result=s.largestOverlap(img1,img2);
    cout<<result;
}