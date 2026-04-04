#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 1) return encodedText;
        int m=encodedText.size()/rows;
        vector<vector<char>> mat(rows, vector<char>(m));
        int num=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j] = encodedText[num++];
            }
        }
        num=0;
        string s="";
        while(num<m)
        {
            for(int i=0;i<rows;i++)
            {
                if(num+i<m)
                {
                    char c=mat[i][i+num];
                    s+=c;
                }
            }
            num++;
        }

        while(!s.empty() && s.back() == ' ')
        {
            s.pop_back();
        }
        return s;

        
    }
};

int main()
{
    Solution s;
    string encodedText="ch   ie   pr";
    int rows=3;
    cout<<s.decodeCiphertext(encodedText,rows);
}