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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prevTail = NULL;
        ListNode* t = head;

    while(t != NULL && t->next != NULL) {
        ListNode* nextPair = t->next->next;
        ListNode* newHead = t->next;

        // swap
        newHead->next = t;
        t->next = nextPair;

        // connect previous
        if(prevTail != NULL) {
            prevTail->next = newHead;
        } else {
            head = newHead;
        }

        prevTail = t;
        t = nextPair;
    }
    return head;   
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    ListNode* res = s.swapPairs(head);
    while(res!=NULL)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
}