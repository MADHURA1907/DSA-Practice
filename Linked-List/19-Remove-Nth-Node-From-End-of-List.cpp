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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* t=head;
        while(t)
        {
            count++;
            t=t->next;
        }

        count=count-n;
        t=head;


        if(count==0)
        {
           ListNode* temp=head;
           head=head->next;
            delete temp;
            return head; 
        }


        for(int i=0;i<count-1;i++)
        {
            t=t->next;
        }


        ListNode* k=t->next;
        t->next=k->next;

        delete k;
        return head;
        
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode* result = sol.removeNthFromEnd(head, n);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}