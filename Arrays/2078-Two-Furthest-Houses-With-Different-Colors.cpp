#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
       int i=0,j=colors.size()-1;
       int m,n;
       while(i<j)
       {
        if(colors[i]!=colors[j])
        {
            m= abs(i-j);
            break;
        }
        i++;
       }
        i=0,j=colors.size()-1;
       while(i<j)
       {
        if(colors[i]!=colors[j])
        {
            n= abs(i-j);
            break;
        }
        j--;
       }
       return max(m,n);

        
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> colors(n);
    for(int i=0;i<n;i++)
        cin>>colors[i];
    cout<<s.maxDistance(colors);
}