#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }   
        int leftsum=0;
        sum=sum-nums[0];
        for(int i=0;i<n;i++)
        {
            answer[i]=abs(leftsum-sum);
            
            leftsum += nums[i];
            if(i<n-1) {sum -= nums[i+1];}
        }
        return answer;     
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {10,4,8,3};
    vector<int> result = obj.leftRightDifference(nums);
    
    cout << "Left Right Difference: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}