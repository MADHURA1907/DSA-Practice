#include <iostream>
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
        {
            return true;
        }
       //1. find middle
        ListNode* t1=head;
        ListNode* t2=head;
        while(t2 && t2->next)
        {
            t1=t1->next;
            t2=t2->next->next;
        }

        //2. reverse the second half
        ListNode* prev=NULL;
        ListNode* curr=t1;
        while(curr)
        {
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }

        //3.compare
        t1=head;
        while(prev)
        {
            if(t1->val!=prev->val)
            {
             return false;   
            }
            t1=t1->next;
            prev=prev->next;
        }
        return true;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    
    bool result = sol.isPalindrome(head);      
    cout << result << endl; 
    
    return 0;
}