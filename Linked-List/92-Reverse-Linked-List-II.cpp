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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
        {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* p = dummy;

        for(int i = 1; i < left; i++)
        {
            p = p->next;
        }

        ListNode* curr = p->next;

        for(int i = 0; i < right - left; i++)
        {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = p->next;
            p->next = temp;
        }

        return dummy->next;
    }
};

int main()
{
    Solution s;
    s.reverseBetween(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 2, 4);
    return 0;
}