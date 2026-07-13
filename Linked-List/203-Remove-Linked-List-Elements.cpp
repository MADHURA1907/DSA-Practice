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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            if(head->val==val)
            {
                ListNode* t=head;
                head=head->next;
                delete t;
            }
            return head;
        }
       ListNode* prev=head;
        ListNode* t1=head->next;
        while(t1!=NULL)
        {
            if(t1->val==val)
            {
                ListNode* t=t1;
                prev->next=t1->next;
                t1=t1->next;
                delete t;
            }
            else
            {
                t1=t1->next;
                prev=prev->next;
            }
        }

        if(head->val==val)
        {
            ListNode* t=head;
            head=head->next;
            delete t;
        }
        return head;
    }
};

int main()
{
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    int val = 6;
    ListNode* result = solution.removeElements(head, val);

    // Print the resulting linked list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}