#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode* t=head;
        while(t)
        {
            arr.push_back(t->val);
            t=t->next;
        }

        swap(arr[k-1],arr[arr.size()-k]);
        t=head;
        int i=0;
        while(t)
        {
            t->val=arr[i];
            i++;
            t=t->next;
        }
        return head;



    }
};

int main() 
{
    Solution s;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    s.swapNodes(head,2);
    return 0;
}